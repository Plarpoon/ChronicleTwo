#!/usr/bin/env python3
"""Build one bounded Discord message for a GitHub push event."""

import argparse
import json
import re
from pathlib import Path


MAX_CONTENT = 2000
MAX_COMMITS = 12
SAFE_REPOSITORY = re.compile(r"^[A-Za-z0-9_.-]+/[A-Za-z0-9_.-]+$")
SAFE_SHA = re.compile(r"^[0-9a-fA-F]{7,64}$")


def discord_length(value):
    return len(value.encode("utf-16-le")) // 2


def plain(value):
    """Keep one display line and prevent source text from changing Markdown."""
    line = " ".join(str(value or "").split())
    return re.sub(r"([\\`*_~|>\[\]()])", r"\\\1", line)


def clipped(value, limit):
    return value if len(value) <= limit else value[:limit - 1].rstrip() + "…"


def commit_line(commit, repository):
    sha = str(commit.get("id", ""))
    subject = clipped(plain(str(commit.get("message", "")).split("\n", 1)[0]) or "(no message)", 110)
    author = clipped(plain((commit.get("author") or {}).get("name", "")), 50)
    detail = f"{subject} — {author}" if author else subject
    if SAFE_REPOSITORY.fullmatch(repository) and SAFE_SHA.fullmatch(sha):
        return f"• [`{sha[:7]}`](https://github.com/{repository}/commit/{sha}) {detail}"
    return f"• {detail}"


def payload(event):
    repository = str(event.get("repository", {}).get("full_name", "ChronicleTwo"))
    commits = event.get("commits") or []
    branch = str(event.get("ref", "")).removeprefix("refs/heads/")
    header = f"**{clipped(plain(repository), 80)}** · {len(commits)} commit{'s' if len(commits) != 1 else ''}"
    if branch:
        header += f" to {clipped(plain(branch), 80)}"

    lines = [clipped(header, MAX_CONTENT)]
    for commit in commits[:MAX_COMMITS]:
        line = commit_line(commit, repository)
        if discord_length("\n".join((*lines, line))) > MAX_CONTENT:
            break
        lines.append(line)

    omitted = len(commits) - (len(lines) - 1)
    if omitted:
        suffix = f"… and {omitted:,} more commit{'s' if omitted != 1 else ''}."
        while discord_length("\n".join((*lines, suffix))) > MAX_CONTENT and len(lines) > 1:
            lines.pop()
            omitted += 1
            suffix = f"… and {omitted:,} more commit{'s' if omitted != 1 else ''}."
        lines.append(suffix)
    elif not commits:
        lines.append("No commits were included in this push event.")

    return {
        "username": "ChronicleTwo",
        "allowed_mentions": {"parse": []},
        "content": "\n".join(lines),
    }


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--event", required=True, type=Path, help="GitHub push event JSON")
    parser.add_argument("output", type=Path, help="Discord webhook payload")
    args = parser.parse_args()
    event = json.loads(args.event.read_text(encoding="utf-8"))
    args.output.write_text(json.dumps(payload(event), ensure_ascii=False) + "\n", encoding="utf-8")


if __name__ == "__main__":
    main()
