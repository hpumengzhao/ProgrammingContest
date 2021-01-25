
T=int(input())
for i in range(1,T+1):
	n,m=map(int,input().split())
	l,r=0,n
	for j in range(130):
		mid=(l+r)//2
		if mid*n-mid*(mid+1)//2>m:
			r=mid
		else:
			#print(mid)
			l=mid
	print(l+1)