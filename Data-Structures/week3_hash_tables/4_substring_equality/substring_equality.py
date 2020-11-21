# python3

import sys
X = int(99)
p1 = int(1e9 + 7);
p2 = int(1e9 + 9);
class Solver:
	def __init__(self, s,h1,h2):
		self.s = s
	#	print(len(s))
		self.h1 = h1
		self.h2 = h2
	#	print(len(h1))
	#	print(len(h2))
		# for i in range(1,len(s)+1):
		# 	h1[i] = X * h1[i-1] + (ord(s[i-1]) - ord('a')+1)
		# 	h1[i] = h1[i] % p1
		# 	h2[i] = X * h2[i-1] + (ord(s[i-1]) - ord('a')+1)
		# 	h2[i] = h2[i] %p2


	def ask(self, a, b, l):
	#	print(a+l);
	#	print(a);
	#	print(len(h1))
	#	print(h1[a+l])
		hb1 = h1[b + l]%p1 - (pow(X,l,p1) * h1[b]%p1)%p1
		ha1 = h1[a + l]%p1 - (pow(X,l,p1) * h1[a]%p1)%p1
		ha2 = h1[a + l]%p2 - (pow(X,l,p2) * h1[a]%p2)%p2
		hb2 = h1[b + l]%p2 - (pow(X,l,p2) * h1[b]%p2)%p2

		return ha1%p1 == hb1%p1 and ha2%p2== hb2%p2

s = sys.stdin.readline()
s = s.strip()
q = int(sys.stdin.readline())
h1 = [0] * (len(s)+1 )
h2 = [0] * (len(s)+1)
# mult1 = int(p1);
# mult2 = int(p2);
# for i in range (len(s),0,-1):
# 	h1[i] = (h1[i-1] + ord(s[i-1] - ord('a') + 1) * mult1) % p1
# 	h2[i] = (h2[i-1] + ord(s[i-1] - ord('a') + 1) * mult2) % p2
# 	mult1 = (mult1 * p1) % p1
# 	mult2 = (mult2 * p2) % p2

solver = Solver(s,h1,h2)
for i in range(q):
	a, b, l = map(int, sys.stdin.readline().split())
	print("Yes" if solver.ask(a, b, l) else "No")
