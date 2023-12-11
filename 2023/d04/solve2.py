#!/usr/bin/python3

import sys

path = 'input.txt'
if (len(sys.argv) >= 2):
	path = sys.argv[1]

f = open(path, 'r')
lines = f.readlines()

sum = 0

amount_table = [1 for _ in lines]

for i, l in enumerate(lines):
	_, card = l.split(':')
	win, pulled = card.split('|')
	win = set(map(int, win.split()))
	pulled = set(map(int, pulled.split()))

	match = len(list(win & pulled))

	print(f"card {i + 1 : > 3}: \x1b[1;33m{match}\x1b[0m * \x1b[1;32m{amount_table[i]}\x1b[0m", end='')

	sum += amount_table[i]

	print(f"\t\x1b[1;35m{sum}\x1b[0m", end='\t')

	for x in range(1, match + 1):
		if (i + x < len(amount_table)):
			amount_table[i + x] += (1 * amount_table[i])
			print(f"{i + x}", end='-')
		else:
			break
	print()

print(sum)
