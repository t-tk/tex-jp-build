#!/usr/bin/env python3
# $Id$
# Applied to tex.ch and mf.ch on 2024-06-03, following the request at:
# https://tug.org/pipermail/tex-k/2024-June/004064.html
"""
Reads a WEB file and a change file and writes a change file to stdout with
potentially corrected part, section and line numbers.
Written by Tyge Thiessen, 2024. Public domain.
"""
import re
import sys

USAGE = f"{sys.argv[0]} <web file> <change file>"


def main():
    if len(sys.argv) != 3:
        print(USAGE)
        sys.exit(1)

    # Read WEB file
    try:
        web_file = open(sys.argv[1], "r")
    except OSError:
        eprint(f"Could not open {sys.argv[1]}")
        print(USAGE)
        sys.exit(1)
    with web_file:
        web_lines = [line.rstrip() for line in web_file]
        web_reader = WebReader(web_lines)

    # Read change file
    try:
        ch_file = open(sys.argv[2], "r")
    except OSError:
        eprint(f"Could not open {sys.argv[2]}")
        print(USAGE)
        sys.exit(1)
    with ch_file:
        ch_lines = [line.rstrip() for line in ch_file]

    ch_reader = ChangeReader(ch_lines)
    ch_reader.traverse(web_reader)
    updated_ch_lines = ch_reader.get_lines()

    for line in updated_ch_lines:
        print(line)


class WebReader:
    """An iterator that produces the lines of a WEB file while keeping track
    of the current part and section number.
    """

    def __init__(self, web_lines):
        self._web_lines = web_lines
        self._pos = 0
        self.part_cnt = 0
        self.section_cnt = 0

    def next_line(self):
        """Returns the triple of current part, section and line numbers, as
        well as the next line. Updates part and section numbers.
        """
        if self._pos >= len(self._web_lines):
            return None
        line = self._web_lines[self._pos]
        self._pos += 1

        part = self.part_cnt
        section = self.section_cnt
        line_number = self._pos

        if re.search("^@\*", line):
            self.part_cnt += 1
            self.section_cnt += 1

        if re.search("^@ ", line):
            self.section_cnt += 1

        return (part, section, line_number), line


class ChangeReader:
    """Reads the lines of a change file while updating the tags with
    information from the corresponding WEB file.
    """

    def __init__(self, ch_lines):
        self._lines = ch_lines
        self._pos = 0
        self._chunk_start = None
        self._match_lines = None

    def advance_to_next_chunk(self):
        """Find the next change chunk. Store where it starts and the lines to be matched."""
        while self._pos < len(self._lines):
            line = self._lines[self._pos]
            if line.startswith("@x"):
                self._chunk_start = self._pos
                while True:
                    self._pos += 1
                    if self._pos >= len(self._lines):
                        eprint(
                            f"ERROR: Missing @y for @x on l.{self._chunk_start + 1} in change file"
                        )
                        sys.exit(1)
                    line = self._lines[self._pos]
                    if line.startswith("@y"):
                        self._match_lines = self._lines[
                            self._chunk_start + 1 : self._pos
                        ]
                        return True
            self._pos += 1
        return False

    def find_match_in_web(self, web_reader):
        """Find the match for the current change chunk in the WEB file.
        Returns the part number and section number just before the first match line,
        as well as the line number of the first match line in the WEB file.
        """
        while True:
            (part, section, line_number), tex_line = web_reader.next_line()
            if tex_line is None:
                eprint("ERROR: Could not find match for line:")
                eprint(f"  {self._match_lines[0]}")
                sys.exit(1)
            if tex_line == self._match_lines[0]:
                for i in range(1, len(self._match_lines)):
                    _, tex_line = web_reader.next_line()
                    if tex_line is None or tex_line != self._match_lines[i]:
                        eprint("ERROR: Could not match all lines following match line:")
                        eprint(f"  {self._match_lines[0]}")
                        sys.exit(1)

                return part, section, line_number

    def traverse(self, web_reader):
        """Go through all individual change chunks while updating their tags."""
        while self.advance_to_next_chunk():
            part, section, line_number = self.find_match_in_web(web_reader)

            # Attempt to catch the case where something is inserted just before
            # the start of a section.
            match_start = self._match_lines[0].strip()[:2]
            repl_start = self._lines[self._pos + 1].strip()[:2]
            if match_start == "@ ":
                if repl_start in ["@ ", "@*"]:
                    section += 1
            elif match_start == "@*":
                if repl_start == "@*":
                    part += 1
                    section += 1
                elif repl_start == "@ ":
                    section += 1

            # Remove leading @x.
            text = self._lines[self._chunk_start][2:].strip()

            # Remove potentially leading [part.section] tag.
            pattern = "\\[.*\\]"
            if re.match(pattern, text):
                text = re.sub(pattern, "", text).strip()

                # Remove potentially line number information.
                pattern = "l\\.\\d+"
                if re.match(pattern, text):
                    text = re.sub(pattern, "", text)
                    pattern = " -+ "
                    # Remove potentially text comment separator.
                    if re.match(pattern, text):
                        text = re.sub(pattern, "", text).strip()

            # Create line with standard tag.
            new_line = f"@x [{part}.{section}] l.{line_number}"

            if text:
                new_line += f" - {text}"

            ch_line = self._lines[self._chunk_start]
            if new_line[:10] != ch_line[:10]:
                print("Old:")
                print(f"  {ch_line}")
                print("New:")
                print(f"  {new_line}")
                print()

            self._lines[self._chunk_start] = new_line

    def get_lines(self):
        return self._lines


def eprint(*args, **kwargs):
    """Print to stderr."""
    print(*args, file=sys.stderr, **kwargs)


if __name__ == "__main__":
    main()
