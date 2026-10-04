// Prints a summary of the current program: language, compiler spec, memory map and analysis state.
// @category ChronicleTwo
import ghidra.app.script.GhidraScript;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;

public class ProgramInfo extends GhidraScript {
    @Override
    protected void run() throws Exception {
        println("language=" + currentProgram.getLanguageID() + " cspec=" + currentProgram.getCompilerSpec().getCompilerSpecID());
        println("image base=" + currentProgram.getImageBase());
        for (MemoryBlock b : currentProgram.getMemory().getBlocks()) {
            println(String.format("block %-12s %s-%s init=%b x=%b", b.getName(), b.getStart(), b.getEnd(), b.isInitialized(), b.isExecute()));
        }
        println("functions=" + currentProgram.getFunctionManager().getFunctionCount());
        println("symbols=" + currentProgram.getSymbolTable().getNumSymbols());
        println("datatypes=" + currentProgram.getDataTypeManager().getDataTypeCount(true));
        println("analyzed=" + currentProgram.getOptions(Program.PROGRAM_INFO).getBoolean(Program.ANALYZED_OPTION_NAME, false));
        int n = 0;
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            if (n++ < 5) println("fn " + f.getEntryPoint() + " " + f.getName(true) + " " + f.getSignature().getPrototypeString());
        }
        var gp = currentProgram.getRegister("gp");
        println("gp at 0x100008=" + currentProgram.getProgramContext().getValue(gp, toAddr(0x100008), false));
        for (String nm : new String[]{"search_txt__Fc", "GetCRC__FPUci"}) {
            for (Symbol s : currentProgram.getSymbolTable().getSymbols(nm)) println("sym " + nm + " @" + s.getAddress());
        }
    }
}
