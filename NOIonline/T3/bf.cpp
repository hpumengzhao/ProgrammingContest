/*
* @author:  codancer
* @createTime:  2020-04-25, 15:24:40
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
const int N = 2e5+100;
ll n,m,x,y;
ll fact[N],inv[N],factinv[N];
void init(){
    fact[0]=inv[1]=factinv[0]=inv[0]=fact[1]=factinv[1]=1;
    for(int i=2;i<=200010;i++){
        fact[i]=(fact[i-1]%mod*i%mod)%mod;
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
        factinv[i]=factinv[i-1]*inv[i]%mod;
    }
}
ll c(ll n,ll m){
    return fact[n]*factinv[m]%mod*factinv[n-m]%mod;
}
ll solve(ll n,ll m){// the number of lengtn n and each number belongs [1,m]
	if(m+n-1<n) return 0;
	return c(m+n-1,n);
}
int main(){
	init();
	scanf("%lld%lld%lld%lld",&n,&m,&x,&y);
	if(y<=n){
		ll left=0;
		rep(i,1,m){
			left+=solve(x-1,i);
			left%=mod;
			left+=solve(n-y,m-i+1);
		}
		ll right=solve(n,m);
		printf("%lld\n", (left*right)%mod);
		return 
	}
	return 0;
}