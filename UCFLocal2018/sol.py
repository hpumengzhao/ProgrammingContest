import math
a=set()
for i in range(0,100):
	for j in range(0,100):
		x=1
		for k in range(i):
			x*=2
		y=1
		for k in range(j):
			y*=5
		now=x*y
		if(now<=1000000000000000000):
			a.add(now)
for v in a:
	print(v)