#!/usr/bin/env python3
"""Generate the objdiff report, as decomp.dev reads it, and summarise it."""

import json
from pathlib import Path
import subprocess


ROOT = Path(__file__).resolve().parents[2]
IMAGE = "SCES_511.90"


def print_summary(report):
    red, green, yellow, gray, reset = "\033[91m", "\033[92m", "\033[93m", "\033[90m", "\033[0m"
    measures = report["measures"]
    units = report["units"]
    fuzzy = sum(1 for unit in units for function in unit.get("functions", ())
                if 0.0 < function.get("fuzzy_match_percent", 0.0) < 100.0)
    perfect = measures.get("matched_functions", 0)
    unmatched = measures.get("total_functions", 0) - perfect - fuzzy
    perfect_share = float(measures.get("matched_code_percent", 0.0))
    fuzzy_share = max(0.0, float(measures.get("fuzzy_match_percent", 0.0)) - perfect_share)
    unmatched_share = 100.0 - perfect_share - fuzzy_share
    print(f"{IMAGE}: {gray}{perfect} perfect, {fuzzy} fuzzy, {unmatched} not decompiled{reset}")
    print("\nCode, by byte")
    for label, color, share, count in (
        ("Perfect", green, perfect_share, perfect),
        ("Fuzzy", yellow, fuzzy_share, fuzzy),
        ("Remaining", red, unmatched_share, unmatched),
    ):
        print(f"  {color}{label:<11}{reset} {share:6.2f}%    {count:5d} functions")
    differences = [(unit["name"], function["name"])
                   for unit in units for function in unit.get("functions", ())
                   if 0.0 < function.get("fuzzy_match_percent", 0.0) < 100.0]
    for unit, function in differences[:10]:
        print(f"    {yellow}fuzzy{reset} {unit}/{function}")
    if len(differences) > 10:
        print(f"    ... and {len(differences) - 10} more")


def main():
    output = ROOT / "progress" / "report.json"
    output.parent.mkdir(parents=True, exist_ok=True)
    subprocess.run(["objdiff-cli", "report", "generate", "--project", str(ROOT),
                    "--output", str(output)], cwd=ROOT, check=True)
    print_summary(json.loads(output.read_text(encoding="utf-8")))


if __name__ == "__main__":
    main()
