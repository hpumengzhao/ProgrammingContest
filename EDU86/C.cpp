/*
* @author:  codancer
* @createTime:  2020-04-26, 23:35:08
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define fep(i,a,b) for(int i=(a);i>=(b);i--)
typedef vector<int> VI;
typedef vector<ll> VII;
typedef pair<int,int> pii;
ll lcm(ll a,ll b){
	return a*b/__gcd(a,b);
}
ll cal(ll lim,ll a,ll x){//[1,lim] % a = x?
	if(x>=a) return 0;
	if(x==0){
		ll num=lim/a;
		return num;
	}else{
		ll num=lim/a;
		if(lim%a>=x) ++num;
		return num;
	}
}
int main(){
	// cout<<cal(6,4,2)<<endl;
	int T;
	scanf("%d",&T);
	while(T--){
		ll a,b,q,l,r;
		scanf("%lld%lld%lld",&a,&b,&q);
		vector<pair<ll,ll> > sa;
		rep(i,0,200){
			rep(j,0,200){
				if((i%a)!=(j%b)){
					sa.push_back({i,j});
				}
			}
		}
		rep(i,1,q){
			ll ans=0;
			scanf("%lld%lld",&l,&r);
			for(ll v:sa){
				ll rr=0;
				ll ll=0;
				rr+=cal(r,a,v);
				rr+=cal(r,b,v);
				rr-=cal(r,lcm(a,b),v);
				ll+=cal(l-1,a,v);
				ll+=cal(l-1,b,v);
				ll-=cal(l-1,lcm(a,b),v);
				ans+=(rr-ll);
			}
			printf("%lld ", ans);
		}
		puts("");
	}
	return 0;
}