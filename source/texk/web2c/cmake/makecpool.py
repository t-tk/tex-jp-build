#!/usr/bin/env python3
import argparse
import os.path
import subprocess
import sys

option_verbose = False
makecpool = "./web2c/makecpool"

def main():
    global option_verbose
    global makecpool

    parser = argparse.ArgumentParser()
    parser.add_argument("basename")
    parser.add_argument("output")
    parser.add_argument("--makecpool", default="./web2c/makecpool")
    parser.add_argument("-v", "--verbose", action="store_true")
    args = parser.parse_args()

    option_verbose = args.verbose
    makecpool = args.makecpool

    basename = args.basename
    output = args.output

    try:
        with open(output, "w") as o:
            subprocess.run([makecpool, basename], check=True, encoding="utf-8", stdout=o)
    except:
        os.unlink(output)

if __name__ == "__main__":
    main()
