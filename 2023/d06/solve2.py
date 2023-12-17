#!/usr/bin/python3

import sys
from collections import namedtuple
from typing import List

Race = namedtuple("Race", ["time", "distance"])

path = 'input.txt'
if (len(sys.argv) >= 2):
	path = sys.argv[1]

f = open(path, 'r')
lines = f.readlines()

_, *times = lines[0].split()
_, *distances = lines[1].split()

time = int(''.join(times))
distance = int(''.join(distances))

def simulate_race(press_time: int, total_time: int):
	return (total_time - press_time) * press_time

sum = 0

r = Race(time, distance)

print(f"⏳\x1b[1;31m{r.time}\x1b[0m\t🏆\x1b[1;33m{r.distance}\x1b[0m\n")

for t in range(r.time):
	dist = simulate_race(t, r.time)

	could_win = dist > r.distance

	percent = t / r.time * 100

	print(f"⏳\x1b[31m{t}\x1b[0m\t📏\x1b[33m{dist}\x1b[0m\t{['🛑','🏅'][could_win]}\t\x1b[1;32m{percent : .2f}%\x1b[0m")

	sum += could_win

print(f"\x1b[1;35m{sum}\x1b[0m\n")

