prime=[]
def is_prime(x):# judge x is a prime number
	if x<=1:
		return False
	if x==2:
		return True
	for i in range(2,100000):
		if(i*i>x):
			break
		if x%i==0:
			return False
	return True

def init():
	for i in range(1,300):
		if is_prime(i):
			prime.append(i)

def getid(x):## 计算x是第几个质数
	ans=-1
	for i in range(len(prime)):
		if x==prime[i]:
			ans=i
			break
	return ans

c = [[0 for i in range(65)] for j in range(100010)]## c[i][j]表示第j个质数在前i个数字出现的个数
def lowbit(x:int)->int:    #求i的二进制数末尾0的格式k，并返回2^k
    return x&(x^(x-1))

def update(id,x,pri):## 在id处+x个pri
	jj=getid(pri)
	i=id
	while i<=100001:
		if i>100001:
			break
		c[i][jj]+=x;
		i=i+lowbit(i)

def query(id,pri):## 查询前id个数有几个pri
	ans=0
	i=id
	jj=getid(pri)
	while i:
		if i<0:
			break
		# print(i,jj)
		ans+=int(c[i][jj])
		i-=lowbit(i)
	return ans
def qpow(a,b):
	ans=1
	aa=a
	bb=b
	while bb:
		if bb%2==1:
			ans=ans*aa
		aa=aa*aa
		bb//=2
	return ans
init()

lst=[0 for i in range(100002)]

for i in range(1,100001):
	lst[i]=3
# update(3,1,3)
for i in range(1,100001):## 初始每个都是3
	update(i,1,3)

n=int(input())
for i in range(1,n+1):
	# print(i)
	ai,bi,ci=map(int,input().split())
	if ai==0:
		ans=1
		for j in range(62):
			num=query(ci,prime[j])-query(bi-1,prime[j])
			# print(prime[j],num)
			if num>0:
				ans*=(prime[j]-1)*qpow(prime[j],num-1)
		print(ans)
	else:
		now=lst[bi]
		lst[bi]=ci
		for v in prime:## -b操作
			if now%v==0:
				cnt=0
				while now%v==0:
					now//=v
					cnt+=1
				update(bi,-cnt,v)
		for v in prime:# +c操作
			if ci%v==0:
				cnt=0
				while ci%v==0:
					ci//=v
					cnt+=1
				update(bi,cnt,v)