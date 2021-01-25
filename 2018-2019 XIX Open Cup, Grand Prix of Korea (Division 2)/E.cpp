#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const int INF=0x3f3f3f3f;
const int maxn=1000000+10;
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
int main(){
	ll a,b,c,d;
	scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
	ll sum=0;
	for(ll x=1;x<999;x++){
		for(ll y=1;y<=999-x;y++){
			if(gcd(x,y)!=1) continue;
			ll l1=(a-1)/x,r1=b/x;
			ll l2=(c-1)/y,r2=d/y;
			sum+=max(0ll,(min(r1,r2)-max(l1,l2)));
		}
	}
	printf("%lld\n",sum);
	return 0;
}
