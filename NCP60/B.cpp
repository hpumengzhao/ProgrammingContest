/*
* @author:  codancer
* @createTime:  2020-03-27, 19:13:27
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 998244353;
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define fep(i,a,b) for(int i=(a);i>=(b);i--)
typedef vector<int> VI;
typedef vector<ll> VII;
typedef pair<int,int> pii;
const int N = 2e3+100;
struct point{
	ll x,y;
}p[N];
ll dis(point a,point b){
	return (abs(a.x-b.x)%mod+abs(a.y-b.y)%mod)%mod;
}
ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1){
			ans=(ans%mod*a%mod)%mod;
		}
		a=(a%mod*a%mod)%mod;
		b>>=1;
	}
	return ans%mod;
}
ll mu(ll a,ll b){
	return (a%mod*b%mod)%mod;
}
ll all[N]={0};
int main(){
	int n;
	cin>>n;
	rep(i,1,n){
		cin>>p[i].x>>p[i].y;
	}
	rep(i,1,n){
		rep(j,1,n){
			all[i]+=dis(p[i],p[j]);
			all[i]%=mod;
		}
	}
	ll ans=0;
	rep(a,1,n){
		rep(b,a+1,n){
			ll x=dis(p[a],p[b]);
			ans+=(((all[a]+all[b])%mod-mu(2,x)+mu(n-2,x))%mod+mod)%mod;
			ans%=mod;
			// cout<<a<<' '<<b<<endl;
		}
	}
	// cout<<ans<<endl;
	cout<<(ans%mod*qpow(3,mod-2)%mod)%mod<<endl;
	return 0;
}