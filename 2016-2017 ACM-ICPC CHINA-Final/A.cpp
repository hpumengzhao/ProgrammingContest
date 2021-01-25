#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll qp(ll a,ll b,ll mod){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
ll res[1000000+10];
int main()
{
	int n,t;
	scanf("%d",&t);
	int cas=1;
	for(ll k=1;k<=100000;k++){
		if((qp(2,k,7)-1+7)%7==0){
			res[k]=res[k-1]+1;
		}else res[k]=res[k-1];
	}
	while(t--){
		scanf("%d",&n);
		printf("Case #%d: %lld\n",cas++,res[n]);
	}
	return 0;
}
