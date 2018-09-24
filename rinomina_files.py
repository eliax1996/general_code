#!/usr/bin/env python
from os import rename, listdir

count = 0
fnames = listdir('.')
badprefix = "Esercitazioni"

for fname in fnames:
    if fname.startswith(badprefix):
        partial = str(count)

        if len(partial) == 1:
            partial = "00" + partial

        if len(partial) == 2:
            partial = "0" + partial

        count += 1

        rename(fname, partial + fname + fname)
