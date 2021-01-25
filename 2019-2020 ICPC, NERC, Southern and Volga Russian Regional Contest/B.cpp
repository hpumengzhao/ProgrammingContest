#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=100000+10;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll num[maxn];
int main()
{
	ll n,k,x;
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x);
		num[x]++;
	}
	sort(num+1,num+k+1);
	ll ans=INF;
	for(ll i=(k+1)/2;i<=k;i++){
		ll cur=0;
		ll q=k-i;
		for(ll j=1;j<=q;j++){
			cur=max(cur,num[j]+num[q*2+1-j]);
		}
		if(q*2!=k) cur=max(cur,num[k]);
		ans=min(ans,cur*i);
//		printf("%d %d\n",cur,q);
	}
	printf("%lld\n",ans);
	return 0;
}
