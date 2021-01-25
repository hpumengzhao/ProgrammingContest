/*
* @author:  codancer
* @createTime:  2020-04-18, 19:26:15
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
ll a[1000000];
ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans%mod;
}
int main(){
	int n;
	scanf("%d",&n);
	ll pw=0;
	ll sum=0;
	rep(i,1,n){
		scanf("%lld",&a[i]);
		pw+=(a[i]*a[i])%mod;
		pw%=mod;
		sum+=a[i];
		sum%=mod;
	}
	ll ans=0;
	rep(i,1,n){
		ans+=((n*a[i])%mod*a[i]%mod)%mod;
		ans%=mod;
		ans-=(2*a[i]*sum)%mod;
		ans+=mod;
		ans%=mod;
		ans+=pw;
		ans%=mod;
	}
	printf("%lld\n",(ans*qpow(2,mod-2))%mod);
	return 0;
}