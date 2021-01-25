/*
* @author:  codancer
* @createTime:  2020-03-22, 12:32:33
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
vector<ll> all;
ll n,k;
bool check(ll x){
	ll ti=0;
	for(int v:all){
		if(v%x==0){
			ti+=(v/x-1);
		}else{
			ti+=(v/x);
		}
	}
	return ti<=k;
}
int main(){
	int T;
	cin>>T;
	int cnt=1;
	while(T--){
		all.clear();
		cin>>n>>k;
		priority_queue<ll> q;
		vector<ll> a(n);
		rep(i,0,n-1){
			cin>>a[i];
		}
		rep(i,0,n-2){
			all.pb(a[i+1]-a[i]);
		}
		// cout<<check(2)<<endl;
		ll l=1;ll r=1e18;
		rep(i,1,200){
			ll mid=(l+r)/2;
			if(check(mid)){
				r=mid;
			}else{
				l=mid;
			}
		}
		printf("Case #%d: %lld\n",cnt++,r);
	}
	return 0;
}