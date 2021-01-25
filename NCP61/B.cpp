/*
* @author:  codancer
* @createTime:  2020-04-10, 19:09:37
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
map<pair<int,int>,ll> dp;
ll getans(ll a,ll b){
	// cout<<a<<' '<<b<<endl;
	if(dp[{a,b}]) return dp[{a,b}];
	if(a==b){
		return dp[{a,b}]=a;
	}
	ll x=min(a,b);
	--x;
	if(x==0){
		if(a<b){
			return dp[{a,b}]=getans(a*2,b)+1;
		}
	}else{
		if(a<b) return dp[{a,b}]=min(getans(a*2,b)+1,getans(a-x,b-x)+x);
	}
}
void solve(){
	ll n,m;
	scanf("%lld %lld",&n,&m);
	if(n>m) swap(n,m);
	// ll ans=0;
	// if(n>m) swap(n,m);
	// while(1){
	// 	if(n==m){
	// 		ans+=n;
	// 		break;
	// 	}
	// 	if(n>m) swap(n,m);
	// 	ll id=0;
	// 	for(ll i=1;i<30;i++){
	// 		if(n*(1LL<<i)>m){
	// 			id=i-1;
	// 			break;
	// 		}
	// 	}
	// 	n*=(1LL<<id);
	// 	ans+=id;
	// 	ll x=n;
	// 	--x;
	// 	ans+=x;
	// 	n-=x;
	// 	m-=x;
	// }
	printf("%lld\n",getans(n,m));
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}