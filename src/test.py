#!/usr/bin/env python3

import sys


def main():

    args = sys.argv[1:3]

    for i in args:
        print(int(i) + 1)

main()
