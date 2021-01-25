/*
* @author:  codancer
* @createTime:  time
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define fep(i,a,b) for(int i=(a);i>=(b);i--)
typedef vector<int> VI;
typedef vector<ll> VII;
typedef pair<int,int> pii;
int cal(int p,int ep){
	if(ep==1){
		return p;
	}
	long long res=1;
	for(int i=1;i<=ep;i++){
		res*=p;
	}
	for(ll i=p;;i+=p){
		ll now=1;
		for(ll j=1;j<=i;j++){
			now*=j;
			now%=res;
		}
		if(now==0){
			return i;
		}
	}
}
bool ok(ll p){
	if(p==1) return 0;
	if(p==2) return 1;
	for(int i=2;i*i<=p;i++){
		if(p%i==0){
			return 0;
		}
	}
	return 1;
}
void solve(){
	ll p;
	cin>>p;
	if(ok(p)){
		cout<<p<<endl;
	}
	else if(p==1){
		cout<<1<<endl;
	}else{
		int ans=0;
		vector<pair<int,int> > fac;
		for(ll i=2;i*i<=p;i++){
			if(p%i==0){
				int cnt=0;
				while(p%i==0){
					p/=i;
					++cnt;
				}
				fac.pb({i,cnt});
			}
		}
		if(p!=1){
			fac.pb({p,1});
		}
		for(auto v:fac){
			ans=max(ans,cal(v.first,v.second));
		}
		cout<<ans<<endl;
	}
}
int main(){
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}