// Writes Ghidra's decompilation of every function in the manifest to
// <out>/<unit>/<symbol>.c and lists the ones that fail in <out>/failures.tsv.
//
// Arguments: manifest path, output directory, worker count, per-function
// timeout in seconds.
// @category ChronicleTwo
import java.io.File;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.util.*;
import java.util.concurrent.*;
import java.util.concurrent.atomic.AtomicInteger;

import ghidra.app.decompiler.*;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.util.task.TaskMonitor;

public class ExportDecomp extends GhidraScript {

    record Row(String unit, String symbol, Address addr) {}

    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        File manifest = new File(args[0]);
        File out = new File(args[1]);
        int workers = args.length > 2 ? Integer.parseInt(args[2]) : 8;
        int timeout = args.length > 3 ? Integer.parseInt(args[3]) : 120;

        List<Row> rows = new ArrayList<>();
        for (String line : Files.readAllLines(manifest.toPath())) {
            if (line.isBlank()) {
                continue;
            }
            String[] f = line.split("\t");
            rows.add(new Row(f[0], f[1], toAddr(Long.parseLong(f[2], 16))));
        }
        out.mkdirs();

        DecompileOptions options = new DecompileOptions();
        options.grabFromProgram(currentProgram);
        BlockingQueue<DecompInterface> pool = new LinkedBlockingQueue<>();
        List<DecompInterface> all = new ArrayList<>();
        for (int i = 0; i < workers; i++) {
            DecompInterface d = new DecompInterface();
            d.setOptions(options);
            d.toggleCCode(true);
            d.toggleSyntaxTree(false);
            d.setSimplificationStyle("decompile");
            if (!d.openProgram(currentProgram)) {
                throw new IllegalStateException("decompiler: " + d.getLastMessage());
            }
            pool.add(d);
            all.add(d);
        }

        ExecutorService exec = Executors.newFixedThreadPool(workers);
        Map<Row, String> failures = new ConcurrentHashMap<>();
        AtomicInteger done = new AtomicInteger();
        AtomicInteger ok = new AtomicInteger();
        List<Future<?>> jobs = new ArrayList<>();
        for (Row r : rows) {
            jobs.add(exec.submit(() -> {
                String reason = null;
                Function f = currentProgram.getFunctionManager().getFunctionAt(r.addr);
                if (f == null) {
                    reason = "no function at " + r.addr;
                }
                else {
                    DecompInterface d = null;
                    try {
                        d = pool.take();
                        DecompileResults res = d.decompileFunction(f, timeout, TaskMonitor.DUMMY);
                        if (res == null || !res.decompileCompleted()
                            || res.getDecompiledFunction() == null) {
                            String msg = res == null ? "no result" : res.getErrorMessage();
                            reason = (msg == null || msg.isBlank()) ? "decompile failed" : msg;
                            if (res != null && res.isTimedOut()) {
                                reason = "timed out after " + timeout + " s";
                            }
                            // A decompiler that failed may be left unusable.
                            d.closeProgram();
                            d.openProgram(currentProgram);
                        }
                        else {
                            File dir = new File(out, r.unit);
                            dir.mkdirs();
                            Files.writeString(new File(dir, r.symbol + ".c").toPath(),
                                res.getDecompiledFunction().getC(), StandardCharsets.UTF_8);
                            ok.incrementAndGet();
                        }
                    }
                    catch (Exception e) {
                        reason = e.toString();
                    }
                    finally {
                        if (d != null) {
                            pool.add(d);
                        }
                    }
                }
                if (reason != null) {
                    failures.put(r, reason.replaceAll("\\s+", " ").trim());
                    new File(new File(out, r.unit), r.symbol + ".c").delete();
                }
                int n = done.incrementAndGet();
                if (n % 250 == 0) {
                    println(n + "/" + rows.size() + " decompiled");
                }
            }));
        }
        for (Future<?> j : jobs) {
            j.get();
        }
        exec.shutdown();
        for (DecompInterface d : all) {
            d.dispose();
        }

        StringBuilder sb = new StringBuilder();
        for (Row r : rows) {
            if (failures.containsKey(r)) {
                sb.append(r.unit).append('\t').append(r.symbol).append('\t')
                        .append(failures.get(r)).append('\n');
            }
        }
        Files.writeString(new File(out, "failures.tsv").toPath(), sb.toString());
        println("decompiled " + ok.get() + ", failed " + failures.size() + " of " + rows.size());
    }
}
