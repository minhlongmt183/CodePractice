n = 300

for e in range(1, n, 1):
	for d in range(1, n, 1):
		for c in range(1, n, 1):
			for b in range(1, n, 1):
				for a in range(1, n, 1):
					if a ** 5 + b ** 5 + c ** 5 + d ** 5 == e ** 5:
						print("{}, {}, {}, {}, {}".format(a,b,c,d,e))
