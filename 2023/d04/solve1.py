#!/usr/bin/python3

f = open('input.txt', 'r')
lines = f.readlines()

sum = 0

for l in lines:
	_, card = l.split(':')
	win, pulled = card.split('|')
	win = set(map(int, win.split()))
	pulled = set(map(int, pulled.split()))

	print('\x1b[1;32m', end='')
	for w in win:
		print(f"{w : > 2}", end='')
	print('\x1b[0m :')

	match = 0

	for p in pulled:
		if (p in win):
			print(f"\x1b[1;33m{p : > 2}\x1b[0m", end='')
			if (match == 0):
				match = 1
			else:
				match *= 2
		else:
			print(f"{p : > 2}", end='')

	print(f"\n-> \x1b[1;35m{match}\x1b[0m")

	sum += match
	print(f" = \x1b[1;3;33m{sum}\x1b[0m\n")