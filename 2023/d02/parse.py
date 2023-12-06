#!/usr/bin/python3

f = open('input.txt', 'r')
lines = f.readlines()

for l in lines:
	_, all_draw = l.split(':')
	all_draw = all_draw.replace(';', ',')

	r = 0
	g = 0
	b = 0
	for c in all_draw.split(','):
		n, color = c.strip().split(' ')

		n = int(n)

		if (color == 'red'):
			r = max(r, n)
		elif (color == 'green'):
			g = max(g, n)
		elif (color == 'blue'):
			b = max(b, n)
		else:
			print("you are a big DUMBASS!")
			exit(1)
	
	print(f"{r} {g} {b}")