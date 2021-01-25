/*
* @author:  codancer
* @createTime:  2020-02-22, 20:52:21
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
#define pb push_back
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef pair<int,int> pii;
const int N = 2e5+100;
ll fact[N],factinv[N],inv[N],n,k;
void init(){
    fact[0]=inv[1]=factinv[0]=inv[0]=fact[1]=factinv[1]=1;
    for(int i=2;i<=N-1;i++){
        fact[i]=(fact[i-1]%mod*i%mod)%mod;
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
        factinv[i]=factinv[i-1]*inv[i]%mod;
    }
}
ll cal(ll n1,ll n0,ll na){
	ll ans=1;
	ans*=fact[n];
	ans%=mod;
	ans*=factinv[n0];
	ans%=mod;
	ans*=factinv[n1];
	ans%=mod;
	ans*=factinv[na];
	ans%=mod;
		//cout<<n1<<' '<<n0<<' '<<na<<' '<<ans<<endl;
	return ans;
}
int main(){
	init();
	cin>>n>>k;
	int ned=n-1;
	ll ans=0;
	if(k<=ned){
		ll n1=n,n0=0,na=0;
		ans+=cal(n1,n0,na);
		ans%=mod;
		n1-=2;n0++,na++;
		ans+=cal(n1,n0,na);
		ans%=mod;
		for(int i=2;i<=k;i++){
			//cout<<n0<<' '<<n1<<' '<<na<<' '<<cal(n1,n0,na)<<endl;
			n0++;
			n1--;
			ans+=cal(n1,n0,na);
			ans%=mod;
		}
	}else{
		ll n1=n,n0=0,na=0;
		ans+=cal(n1,n0,na);
		ans%=mod;
		n1-=2;n0++,na++;
		ans+=cal(n1,n0,na);
		ans%=mod;
		for(int i=2;i<=ned;i++){
			if(i==ned&&(k-ned)&1) continue;
			n1--;
			n0++;
			ans+=cal(n1,n0,na);
			ans%=mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}