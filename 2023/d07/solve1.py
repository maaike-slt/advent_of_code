#!/usr/bin/python3

import sys
from collections import namedtuple
from typing import List, Dict
from functools import cmp_to_key

Player = namedtuple("Player", ["hand", "bid"])

path = 'input.txt'
if (len(sys.argv) >= 2):
	path = sys.argv[1]

f = open(path, 'r')
lines = f.readlines()

players: List[Player] = []

for l in lines:
	h, b = l.split()
	players.append(Player(h, int(b)))

def char_score(c: str) -> int:
	if c >= '2' and c <= '9':
		return int(c)
	elif c == 'T':
		return 10
	elif c == 'J':
		return 11
	elif c == 'Q':
		return 12
	elif c == 'K':
		return 13
	elif c == 'A':
		return 14

def hand_score(hand: str) -> int:
	h: Dict[str, int] = {}

	for c in hand:
		n = h.get(c, 0)
		h[c] = n + 1

	if len(h) == 1:
		return 7
	elif len(h) == 2 \
			and any(n == 4 for n in h.values()):
		return 6
	elif len(h) == 2 \
			and any(n == 3 for n in h.values()) \
			and any(n == 2 for n in h.values()):
		return 5
	elif len(h) == 3 \
			and any(n == 3 for n in h.values()):
		return 4
	elif len(h) == 3:
		return 3
	elif len(h) == 4:
		return 2
	elif len(h) == 5:
		return 1
	else:
		raise Exception("YOU FUCKED UP HARD!")

def comp(p1: Player, p2: Player) -> int:
	s1 = hand_score(p1.hand)
	s2 = hand_score(p2.hand)
	
	if s1 < s2:
		return 1
	elif s1 > s2:
		return -1

	# hand equal let's check each char

	for i in range(len(p1.hand)):
		c1 = char_score(p1.hand[i])
		c2 = char_score(p2.hand[i])

		if c1 < c2:
			return 1
		elif c1 > c2:
			return -1

	raise Exception(f"player: {p1} has same hand as player: {p2}")

players = sorted(players, key=cmp_to_key(comp))

sum = 0

for i, p in enumerate(players):
	rank = len(players) - i

	gain = p.bid * rank

	print(f"🏆\x1b[1;36m{rank}\x1b[0m" \
	   + f": 🃏\x1b[1;34m{p.hand}\x1b[0m = \x1b[1;35m{hand_score(p.hand)}\x1b[0m"
	   + f"\t💰\x1b[1;33m{p.bid}\x1b[0m -> 💸\x1b[1;35m{gain}\x1b[0m")

	sum += gain

print(f"\n\x1b[1;35m{sum}\x1b[0m")	
