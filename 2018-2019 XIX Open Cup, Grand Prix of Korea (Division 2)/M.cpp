#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
const ll INF=0x3f3f3f3f;
const ll maxn=1000000+10;
struct peo{
	ll s,t;
}p[maxn];
ll n,k,a;
ll cal(ll s,ll t){
	ll ans=0;
	ll res=k;
	for(;;){
		if(res>s*a){
			res-=s*a;
			ans+=s;
			ans+=t;
		}else{
			ans+=res/a;
			res=0;break;
		}
	}
	return ans;
}
int main(){
	cin>>n>>k>>a;
	for(ll i=1;i<=n;i++){
		cin>>p[i].s>>p[i].t;
	}
	long long ans=9999999999999999;
	for(ll i=1;i<=n;i++){
		ans=min(ans,cal(p[i].s,p[i].t));
	}
	cout<<ans<<endl;
	return 0;
}
