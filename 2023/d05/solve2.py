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
seed = list(map(int, seed))

tmp = []
i = 0
while i < len(seed):
	for x in range(seed[i + 1]):
		tmp.append(seed[i] + x)
	i += 2
seed = tmp

def map_seed(m: str, seed: List[int]):
	name, *L = m.split('\n')

	output=[]

	print('-'*60)
	print(f"\x1b[1;34m{name}\x1b[0m")

	arr: list[Range] = []
	for l in L:
		if (len(l) == 0):
			continue
		r_o, r_i, r_l = map(int, l.split())
		arr.append(Range(r_i, r_o, r_l))
	
	# for a in arr:
	# 	print(f"{a.input}->{a.output} ::{a.len}")
	
	for s in seed:
		found = False

		for a in arr:
			if not (s >= a.input and s < a.input + a.len):
				continue
			
			found = True

			output.append(s - a.input + a.output)

			break

		if not found:
			output.append(s)
	
	return output


for m in M:
	seed = map_seed(m, seed)
	print(f"\x1b[1;35m{' '.join(map(str, seed))}\x1b[0m")

seed = list(map(str, sorted(seed)))

print(f"\n\x1b[1;32m{seed[0]} \x1b[1;35m{' '.join(seed[1:])}\x1b[0m")