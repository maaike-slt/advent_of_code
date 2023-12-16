#!/usr/bin/python3

import sys
from collections import namedtuple
from typing import List

Range = namedtuple("Range", ["input", "output", "len"])

path = 'input.txt'
if (len(sys.argv) >= 2):
	path = sys.argv[1]

f = open(path, 'r')
lines = f.readlines()

a = ''.join(lines)

section = a.split('\n\n')

seed, *M = section

name, *seed = seed.split()
print(f"""\x1b[1;34m{name}\x1b[0m
\x1b[1;35m{' '.join(seed)}\x1b[0m""")
seed = map(int, seed)

# for each map, convert our seeds

def map_seed(m: str, seed: List[int]):
	name, *L = m.split('\n')

	output=[]

	print('-'*60)
	print(f"\x1b[1;34m{name}\x1b[0m")

	arr: list[Range] = []
	for l in L:
		if (len(l) == 0):
			continue
		r_i, r_o, r_l = map(int, l.split())
		arr.append(Range(r_i, r_o, r_l))
	
	for a in arr:
		print(f"{a.input} {a.output} {a.len}")
	
	for s in seed:
		found = False

		for a in arr:
			if not (s >= a.input and s < a.input + a.len):
				continue
			
			found = True

			diff = a.input - a.output

			output.append(s + diff)

			break

		if not found:
			output.append(s)
	
	return output


for m in M:
	seed = map_seed(m, seed)
	print(f"\x1b[1;35m{' '.join(map(str, seed))}\x1b[0m")