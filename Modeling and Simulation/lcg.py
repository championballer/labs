import random

def lcg(m,a,c,s,n):
	for c in range(n):
		s = (a*s+c)%m
		print(s)

seed = random.randint(1,2**15)
n = int(input("Enter count of random numbers : "))
a = 10
c = 11
m = 19

lcg(m,a,c,seed,n)