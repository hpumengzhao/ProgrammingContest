from functools import reduce
import fractions
def LCM(a,b):
    a=int(a)
    b=int(b)
    return a*b/fractions.gcd(a,b)
n=int(input())
lst= list(map(int,input().split()))
res=reduce(LCM, lst, 1)
ans=0
for x in lst:
    ans+=res//x
print(ans%(10**9+7))
