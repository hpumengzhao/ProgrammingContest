#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const int maxn=1000000+10;
const int INF=0x3f3f3f3f;
const ll mod=1e9+7;
ll qp(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int main()
{
	ll t,n,k;
	scanf("%lld",&t);
	for(int x=1;x<=t;x++){
		scanf("%lld %lld",&n,&k);
		ll res=qp(2,n)-1;
		ll cur=1;
		for(int i=1;i<k;i++){
			cur=cur*(n-i+1)%mod*qp(i,mod-2)%mod;
			res=(res-cur+mod)%mod;
		}
		printf("Case #%d: %lld\n",x,res);
	}
	return 0;
}
