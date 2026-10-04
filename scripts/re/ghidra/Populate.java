// Populates the program with the project's symbols and with the types the
// CodeWarrior-mangled names and the SDK headers state.
//
// Argument: the directory scripts/re/ghidra/prepare.py wrote. Optional second
// argument `reanalyze` runs auto-analysis even when the program has had it.
//
// Every step looks up what exists before creating, so a second run changes
// nothing that the first one made and creates no duplicates.
// @category ChronicleTwo
import java.io.File;
import java.math.BigInteger;
import java.nio.file.Files;
import java.util.*;

import com.google.gson.*;

import ghidra.app.cmd.function.ApplyFunctionSignatureCmd;
import ghidra.app.cmd.function.FunctionRenameOption;
import ghidra.app.util.NamespaceUtils;
import ghidra.app.script.GhidraScript;
import ghidra.app.util.cparser.C.CParser;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.lang.Register;
import ghidra.program.model.listing.*;
import ghidra.program.model.listing.Function.FunctionUpdateType;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.*;
import ghidra.program.util.GhidraProgramUtilities;

public class Populate extends GhidraScript {
    static final long GP = 0x3846F0L;
    static final CategoryPath GAME = new CategoryPath("/game");
    static final CategoryPath SCE = new CategoryPath("/sce");
    static final String THISCALL = "__thiscall";

    File work;
    DataTypeManager dtm;
    SymbolTable st;
    FunctionManager fm;
    Listing listing;

    /** One row of symbols.tsv. */
    record Sym(Address addr, String name, String retail, String kind, long size, String unit) {}

    List<Sym> syms = new ArrayList<>();
    Map<Address, Sym> byAddr = new HashMap<>();
    Set<List<String>> classPaths = new HashSet<>();
    Map<String, Integer> counts = new TreeMap<>();

    void count(String key) {
        counts.merge(key, 1, Integer::sum);
    }

    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        work = new File(args.length > 0 ? args[0] : "build/re/ghidra-work");
        boolean reanalyze = args.length > 1 && args[1].equals("reanalyze");
        dtm = currentProgram.getDataTypeManager();
        st = currentProgram.getSymbolTable();
        fm = currentProgram.getFunctionManager();
        listing = currentProgram.getListing();

        readSymbols();
        setGlobalPointer();
        defineFunctions();
        labelSymbols();
        boolean analyzed = GhidraProgramUtilities.isAnalyzed(currentProgram);
        if (!analyzed || reanalyze) {
            // The GNU demangler reads CodeWarrior names as GNU v2 ones and gets
            // the details wrong; the signatures come from this script instead.
            setAnalysisOption(currentProgram, "Demangler GNU", "false");
            println("running auto-analysis");
            analyzeAll(currentProgram);
            GhidraProgramUtilities.markProgramAnalyzed(currentProgram);
            // Analysis may have moved bodies or names; restate them.
            defineFunctions();
            labelSymbols();
        }
        defineData();
        applySdkTypes();
        applyMangledSignatures();
        applyVtables();
        for (var e : counts.entrySet()) {
            println(String.format("%-32s %d", e.getKey(), e.getValue()));
        }
    }

    // ---------------------------------------------------------------- symbols

    void readSymbols() throws Exception {
        for (String line : Files.readAllLines(new File(work, "symbols.tsv").toPath())) {
            if (line.isEmpty()) {
                continue;
            }
            String[] f = line.split("\t", -1);
            Sym s = new Sym(toAddr(Long.parseLong(f[0], 16)), f[1], f[2], f[3],
                Long.parseLong(f[4], 16), f[5]);
            syms.add(s);
            byAddr.put(s.addr, s);
        }
        // Ends of functions without an ELF size: the next symbol.
        println("read " + syms.size() + " symbols");
    }

    void setGlobalPointer() throws Exception {
        Register gp = currentProgram.getRegister("gp");
        BigInteger value = BigInteger.valueOf(GP);
        for (MemoryBlock b : currentProgram.getMemory().getBlocks()) {
            if (b.isExecute() && b.isInitialized() && b.getName().equals("main")) {
                currentProgram.getProgramContext().setValue(gp, b.getStart(), b.getEnd(), value);
            }
        }
        Symbol gpSym = st.getGlobalSymbol("_gp", toAddr(GP));
        if (gpSym == null) {
            st.createLabel(toAddr(GP), "_gp", SourceType.USER_DEFINED);
        }
    }

    AddressSet bodyOf(Sym s) {
        long size = s.size;
        if (size <= 0) {
            // No ELF size: run to the next symbol.
            Sym next = null;
            int i = syms.indexOf(s);
            for (int j = i + 1; j < syms.size(); j++) {
                if (syms.get(j).kind.equals("func")) {
                    next = syms.get(j);
                    break;
                }
            }
            size = next == null ? 4 : next.addr.subtract(s.addr);
        }
        return new AddressSet(s.addr, s.addr.add(size - 1));
    }

    void defineFunctions() throws Exception {
        for (Sym s : syms) {
            if (!s.kind.equals("func")) {
                continue;
            }
            AddressSet body = bodyOf(s);
            if (listing.getInstructionAt(s.addr) == null) {
                disassemble(s.addr);
            }
            Function f = fm.getFunctionAt(s.addr);
            // Functions analysis created inside this body, and bodies reaching into it.
            List<Function> overlapping = new ArrayList<>();
            fm.getFunctionsOverlapping(body).forEachRemaining(overlapping::add);
            for (Function g : overlapping) {
                if (f != null && g.equals(f)) {
                    continue;
                }
                if (body.contains(g.getEntryPoint())) {
                    Sym owner = byAddr.get(g.getEntryPoint());
                    if (owner == null || !owner.kind.equals("func")) {
                        fm.removeFunction(g.getEntryPoint());
                        count("functions removed (inside another)");
                    }
                }
                else {
                    AddressSetView rest = g.getBody().subtract(body);
                    if (!rest.isEmpty() && rest.contains(g.getEntryPoint())) {
                        g.setBody(rest);
                    }
                }
            }
            if (f == null) {
                f = fm.createFunction(s.name, s.addr, body, SourceType.USER_DEFINED);
                count("functions created");
            }
            else if (!f.getBody().equals(body)) {
                f.setBody(body);
                count("function bodies set");
            }
            if (!f.getName().equals(s.name)) {
                f.setName(s.name, SourceType.USER_DEFINED);
                count("functions renamed");
            }
        }
    }

    void labelSymbols() throws Exception {
        for (Sym s : syms) {
            if (s.kind.equals("func")) {
                continue;
            }
            Symbol existing = null;
            for (Symbol sym : st.getSymbols(s.addr)) {
                if (sym.getName().equals(s.name)) {
                    existing = sym;
                }
            }
            if (existing == null) {
                existing = st.createLabel(s.addr, s.name, SourceType.USER_DEFINED);
                count("labels created");
            }
            if (!existing.isPrimary() && existing.getSymbolType() == SymbolType.LABEL) {
                existing.setPrimary();
            }
        }
    }

    // ------------------------------------------------------------------- data

    void defineData() throws Exception {
        for (Sym s : syms) {
            if (!s.kind.equals("object") || s.size <= 0 || s.name.startsWith("__vt__")) {
                continue;
            }
            Address end = s.addr.add(s.size - 1);
            if (!currentProgram.getMemory().contains(s.addr, end)) {
                continue;
            }
            boolean clear = true;
            for (Address a = s.addr; a.compareTo(end) <= 0; ) {
                CodeUnit cu = listing.getCodeUnitContaining(a);
                if (cu == null) {
                    a = a.next();
                    continue;
                }
                if (cu instanceof Instruction || (cu instanceof Data d && d.isDefined())) {
                    clear = false;
                    break;
                }
                a = cu.getMaxAddress().next();
                if (a == null) {
                    break;
                }
            }
            if (!clear) {
                continue;
            }
            DataType dt;
            long n = s.size;
            if (n == 1 || n == 2 || n == 4 || n == 8) {
                dt = Undefined.getUndefinedDataType((int) n);
            }
            else if (n % 4 == 0 && s.addr.getOffset() % 4 == 0) {
                dt = new ArrayDataType(Undefined4DataType.dataType, (int) (n / 4), 4, dtm);
            }
            else {
                dt = new ArrayDataType(Undefined1DataType.dataType, (int) n, 1, dtm);
            }
            try {
                listing.createData(s.addr, dt);
                count("data defined");
            }
            catch (Exception e) {
                count("data not defined (conflict)");
            }
        }
    }

    // -------------------------------------------------------------- SDK types

    void applySdkTypes() throws Exception {
        String text = Files.readString(new File(work, "sdk.h").toPath());
        StandAloneDataTypeManager tmp = new StandAloneDataTypeManager("sdk");
        tmp.setProgramArchitecture(currentProgram.getLanguage(),
            currentProgram.getCompilerSpec().getCompilerSpecID(),
            StandAloneDataTypeManager.LanguageUpdateOption.CLEAR, monitor);
        int tx = tmp.startTransaction("parse");
        CParser parser = new CParser(tmp, true, null);
        try {
            parser.parse(text);
        }
        catch (Exception e) {
            printerr("SDK header parse failed: " + e.getMessage());
            tmp.endTransaction(tx, false);
            return;
        }
        // Everything the parser made moves under /sce before it reaches the program.
        List<DataType> made = new ArrayList<>();
        tmp.getAllDataTypes(made);
        Category sce = tmp.createCategory(SCE);
        for (DataType dt : made) {
            if (dt instanceof BuiltInDataType || dt instanceof Pointer || dt instanceof Array) {
                continue;
            }
            if (dt instanceof FunctionDefinition) {
                continue;
            }
            if (!dt.getCategoryPath().equals(SCE)) {
                try {
                    sce.moveDataType(dt, DataTypeConflictHandler.REPLACE_HANDLER);
                }
                catch (Exception e) {
                    // A same-named type already moved.
                }
            }
        }
        for (DataType dt : made) {
            if (dt.getCategoryPath().equals(SCE) && !(dt instanceof FunctionDefinition)) {
                dtm.resolve(dt, DataTypeConflictHandler.REPLACE_HANDLER);
                count("SDK types");
            }
        }
        for (var e : parser.getFunctions().entrySet()) {
            if (!(e.getValue() instanceof FunctionDefinition def)) {
                continue;
            }
            for (Symbol sym : st.getGlobalSymbols(e.getKey())) {
                Function f = fm.getFunctionAt(sym.getAddress());
                if (f == null) {
                    continue;
                }
                FunctionDefinition copy = (FunctionDefinition) def.copy(dtm);
                ApplyFunctionSignatureCmd cmd = new ApplyFunctionSignatureCmd(f.getEntryPoint(),
                    copy, SourceType.USER_DEFINED, true, FunctionRenameOption.NO_CHANGE);
                if (cmd.applyTo(currentProgram, monitor)) {
                    count("SDK prototypes applied");
                }
                else {
                    printerr("SDK prototype " + e.getKey() + ": " + cmd.getStatusMsg());
                }
            }
        }
        tmp.endTransaction(tx, true);
        tmp.close();
    }

    // -------------------------------------------------------- mangled names

    Namespace namespaceFor(List<String> path, boolean lastIsClass) throws Exception {
        Namespace ns = currentProgram.getGlobalNamespace();
        for (int i = 0; i < path.size(); i++) {
            String name = path.get(i);
            boolean asClass = (i == path.size() - 1 && lastIsClass)
                || classPaths.contains(path.subList(0, i + 1));
            Namespace child = st.getNamespace(name, ns);
            if (child == null) {
                child = asClass ? st.createClass(ns, name, SourceType.USER_DEFINED)
                        : st.createNameSpace(ns, name, SourceType.USER_DEFINED);
                count(asClass ? "classes created" : "namespaces created");
            }
            else if (asClass && !(child instanceof GhidraClass)) {
                child = NamespaceUtils.convertNamespaceToClass(child);
            }
            ns = child;
        }
        return ns;
    }

    /** The placeholder structure for a class: empty until its layout is known. */
    DataType classStruct(List<String> path) {
        CategoryPath cat = GAME;
        for (int i = 0; i < path.size() - 1; i++) {
            cat = cat.extend(path.get(i));
        }
        String name = path.get(path.size() - 1);
        DataType dt = dtm.getDataType(cat, name);
        if (dt == null) {
            dt = dtm.addDataType(new StructureDataType(cat, name, 0, dtm),
                DataTypeConflictHandler.KEEP_HANDLER);
            count("placeholder structs created");
        }
        return dt;
    }

    static List<String> pathOf(JsonArray a) {
        List<String> out = new ArrayList<>();
        for (JsonElement e : a) {
            out.add(e.getAsString());
        }
        return out;
    }

    DataType primitive(String n) {
        return switch (n) {
            case "void" -> VoidDataType.dataType;
            case "bool" -> BooleanDataType.dataType;
            case "char" -> CharDataType.dataType;
            case "schar" -> SignedCharDataType.dataType;
            case "uchar" -> UnsignedCharDataType.dataType;
            case "short" -> ShortDataType.dataType;
            case "ushort" -> UnsignedShortDataType.dataType;
            case "int" -> IntegerDataType.dataType;
            case "uint" -> UnsignedIntegerDataType.dataType;
            case "long" -> LongDataType.dataType;
            case "ulong" -> UnsignedLongDataType.dataType;
            case "longlong" -> LongLongDataType.dataType;
            case "ulonglong" -> UnsignedLongLongDataType.dataType;
            case "float" -> FloatDataType.dataType;
            case "double" -> DoubleDataType.dataType;
            case "longdouble" -> LongDoubleDataType.dataType;
            case "wchar" -> WideCharDataType.dataType;
            default -> throw new IllegalArgumentException(n);
        };
    }

    /** A parameter type; a class passed by value arrives as a pointer to a copy. */
    DataType paramType(JsonObject t) {
        DataType dt = type(t);
        if (t.get("k").getAsString().equals("class")) {
            return new PointerDataType(dt, dtm);
        }
        return dt;
    }

    DataType type(JsonObject t) {
        switch (t.get("k").getAsString()) {
            case "prim":
                return primitive(t.get("n").getAsString());
            case "class":
                return classStruct(pathOf(t.getAsJsonArray("path")));
            case "ptr":
            case "ref":
                return new PointerDataType(type(t.getAsJsonObject("t")), dtm);
            case "arr": {
                DataType el = type(t.getAsJsonObject("t"));
                int n = t.get("n").getAsInt();
                if (el.getLength() <= 0) {
                    throw new IllegalArgumentException("array of unsized type");
                }
                return new ArrayDataType(el, n, el.getLength(), dtm);
            }
            case "fn": {
                FunctionDefinitionDataType fd = new FunctionDefinitionDataType(
                    CategoryPath.ROOT, "fn", dtm);
                List<ParameterDefinition> ps = new ArrayList<>();
                boolean varargs = false;
                for (JsonElement p : t.getAsJsonArray("params")) {
                    JsonObject po = p.getAsJsonObject();
                    if (po.get("k").getAsString().equals("prim")) {
                        String n = po.get("n").getAsString();
                        if (n.equals("...")) {
                            varargs = true;
                            continue;
                        }
                        if (n.equals("void")) {
                            continue;
                        }
                    }
                    ps.add(new ParameterDefinitionImpl(null, paramType(po), null));
                }
                fd.setArguments(ps.toArray(new ParameterDefinition[0]));
                fd.setReturnType(type(t.getAsJsonObject("ret")));
                fd.setVarArgs(varargs);
                // Anonymous: Ghidra names it by its signature.
                String name = fd.getPrototypeString().replaceAll("[^A-Za-z0-9_]+", "_");
                FunctionDefinitionDataType named = new FunctionDefinitionDataType(
                    GAME.extend("functypes"), name, fd, dtm);
                return dtm.resolve(named, DataTypeConflictHandler.KEEP_HANDLER);
            }
        }
        throw new IllegalArgumentException(t.toString());
    }

    void applyMangledSignatures() throws Exception {
        List<JsonObject> sigs = new ArrayList<>();
        for (String line : Files.readAllLines(new File(work, "signatures.jsonl").toPath())) {
            if (!line.isBlank()) {
                sigs.add(JsonParser.parseString(line).getAsJsonObject());
            }
        }
        // Every name that qualifies a member function or vtable is a class.
        for (JsonObject sig : sigs) {
            if (sig.get("kind").getAsString().equals("function")) {
                continue;
            }
            classPaths.add(pathOf(sig.getAsJsonArray("class")));
        }
        for (String line : Files.readAllLines(new File(work, "vtables.tsv").toPath())) {
            if (!line.isBlank()) {
                classPaths.add(pathOf(JsonParser.parseString(line.split("\t")[2]).getAsJsonArray()));
            }
        }
        for (JsonObject sig : sigs) {
            monitor.checkCancelled();
            Address addr = toAddr(Long.parseLong(sig.get("address").getAsString(), 16));
            Function f = fm.getFunctionAt(addr);
            if (f == null) {
                printerr("no function at " + addr);
                continue;
            }
            try {
                applySignature(f, sig);
                count("functions typed from mangled names");
            }
            catch (Exception e) {
                printerr(sig.get("name").getAsString() + ": " + e);
                count("mangled signatures not applied");
            }
        }
    }

    void applySignature(Function f, JsonObject sig) throws Exception {
        String kind = sig.get("kind").getAsString();
        boolean member = !kind.equals("function");
        if (sig.get("class").isJsonArray()) {
            Namespace ns = namespaceFor(pathOf(sig.getAsJsonArray("class")), member);
            if (!f.getParentNamespace().equals(ns)) {
                f.setParentNamespace(ns);
            }
        }
        List<Parameter> params = new ArrayList<>();
        Parameter[] old = f.getParameters();
        int i = 0;
        for (JsonElement p : sig.getAsJsonArray("params")) {
            DataType dt = paramType(p.getAsJsonObject());
            params.add(new ParameterImpl(keptName(old, i, member), dt, currentProgram));
            i++;
        }
        if (kind.equals("dtor")) {
            // MWCC destructors take a flag saying whether to free the object.
            params.add(new ParameterImpl("delete_flag", ShortDataType.dataType, currentProgram));
        }
        Variable ret = null;
        if (kind.equals("ctor") || kind.equals("dtor")) {
            // Both hand back `this`.
            DataType cls = classStruct(pathOf(sig.getAsJsonArray("class")));
            ret = new ReturnParameterImpl(new PointerDataType(cls, dtm), currentProgram);
        }
        String cc = member ? THISCALL : f.getCallingConventionName();
        if (cc == null || cc.equals(Function.UNKNOWN_CALLING_CONVENTION_STRING)) {
            cc = currentProgram.getCompilerSpec().getDefaultCallingConvention().getName();
        }
        f.updateFunction(cc, ret, params, FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true,
            SourceType.USER_DEFINED);
        f.setVarArgs(sig.get("varargs").getAsBoolean());
        String comment = sig.get("demangled").getAsString();
        if (!comment.equals(f.getComment())) {
            f.setComment(comment);
        }
        if (sig.get("const").getAsBoolean()) {
            count("const member functions");
        }
    }

    /** A parameter name someone gave by hand survives a rerun. */
    static String keptName(Parameter[] old, int index, boolean member) {
        int at = index + (member ? 1 : 0);
        if (at < old.length && old[at].getSource() == SourceType.USER_DEFINED
            && !old[at].getName().startsWith("param_") && !old[at].isAutoParameter()) {
            return old[at].getName();
        }
        return null;
    }

    // ---------------------------------------------------------------- vtables

    void applyVtables() throws Exception {
        DataType rtti = new PointerDataType(VoidDataType.dataType, dtm);
        FunctionDefinitionDataType vfuncDef = new FunctionDefinitionDataType(GAME, "vfunc", dtm);
        DataType vfunc = dtm.resolve(vfuncDef, DataTypeConflictHandler.KEEP_HANDLER);
        for (String line : Files.readAllLines(new File(work, "vtables.tsv").toPath())) {
            if (line.isBlank()) {
                continue;
            }
            String[] f = line.split("\t");
            Address addr = toAddr(Long.parseLong(f[0], 16));
            List<String> path = pathOf(JsonParser.parseString(f[2]).getAsJsonArray());
            int size = Integer.parseInt(f[3], 16);
            int entries = size / 4 - 2;
            if (entries < 0) {
                continue;
            }
            classStruct(path);
            CategoryPath cat = GAME;
            for (int i = 0; i < path.size() - 1; i++) {
                cat = cat.extend(path.get(i));
            }
            String name = path.get(path.size() - 1) + "_vtable";
            // CodeWarrior's layout: RTTI, the offset of the object holding this
            // vtable pointer, then the virtual functions.
            StructureDataType s = new StructureDataType(cat, name, 0, dtm);
            s.add(rtti, "rtti", null);
            s.add(IntegerDataType.dataType, "this_offset", null);
            if (entries > 0) {
                DataType ptr = new PointerDataType(vfunc, dtm);
                s.add(new ArrayDataType(ptr, entries, 4, dtm), "functions", null);
            }
            DataType vt = dtm.resolve(s, DataTypeConflictHandler.REPLACE_HANDLER);
            Data d = listing.getDataAt(addr);
            if (d == null || !d.getDataType().isEquivalent(vt)) {
                listing.clearCodeUnits(addr, addr.add(size - 1), false);
                listing.createData(addr, vt);
            }
            Namespace ns = namespaceFor(path, true);
            for (Symbol sym : st.getSymbols(addr)) {
                if (sym.getName().equals(f[1]) && !sym.getParentNamespace().equals(ns)) {
                    sym.setNamespace(ns);
                }
            }
            count("vtables typed");
        }
    }
}
