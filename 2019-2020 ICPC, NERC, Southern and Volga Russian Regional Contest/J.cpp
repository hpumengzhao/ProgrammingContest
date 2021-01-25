#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1000000+10;
ll n,k;
ll c[maxn],cc[maxn];
bool check(ll x){
	ll num=0;
	for(ll i=1;i<=n;i++) cc[i]=c[i];
	cc[n+1]=0;
	for(ll i=1;i<=n;i++){
		num+=cc[i]/x;
		cc[i]%=x;
		if(cc[i]+cc[i+1]>=x){
			cc[i+1]-=x-cc[i];
			cc[i]=0;
			num++;
		}
	}
	return num>=k;
}
ll cal(ll x){
	ll num=0;
	for(ll i=1;i<=n;i++) cc[i]=c[i];
	cc[n+1]=0;
	for(ll i=1;i<=n;i++){
		num+=cc[i]/x;
		cc[i]%=x;
		if(cc[i]+cc[i+1]>=x){
			cc[i+1]-=x-cc[i];
			cc[i]=0;
			num++;
		}
	}
	return num;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%lld %lld",&n,&k);
		for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
		ll l=1,r=2000000000000ll;
		while(l<=r){
			ll m=(l+r)/2;
			if(check(m)) l=m+1;
			else r=m-1;
		}
		printf("%lld\n",(l-1)*k);
	}
	return 0;
}
