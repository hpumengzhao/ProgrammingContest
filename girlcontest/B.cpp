/*
* @author:  codancer
* @createTime:  2020-04-25, 20:10:12
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((ll)(x).size())
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define fep(i,a,b) for(ll i=(a);i>=(b);i--)
typedef vector<ll> VI;
typedef vector<ll> VII;
typedef pair<ll,ll> pii;
const ll N = 1e6+100;
ll a[N];
ll L,n,m;
bool check(ll x){
	ll last=0;
	ll cnt=0;
	rep(i,1,n+1){
		if(a[i]-a[last]>x&&last==i-1) return 0;
		if(a[i]-a[last]==x){
			++cnt;
			last=i;
			continue;
		}
		if(a[i]-a[last]<x){
			if(i==n+1) ++cnt;
			continue;
		}
		if(a[i]-a[last]>x){
			++cnt;
			last=i-1;
			--i;
		}
	}
	if(a[n+1]-a[last]>x) ++cnt;
	//++cnt;
	return cnt<=m;
}
int main(){
	while(cin>>L>>n>>m){
		a[0]=0;
		a[n+1]=L;
		rep(i,1,n)cin>>a[i];
		sort(a,a+n+2);
		ll l=0;ll r=1e18;
		rep(i,1,100){
			ll mid=(l+r)/2;
			if(check(mid)) r=mid;
			else l=mid;
		}
		cout<<r<<endl;
	}
	return 0;
}