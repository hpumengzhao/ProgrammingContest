/*
* @author:  codancer
* @createTime:  2020-04-12, 21:02:02
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
ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans%mod;	
}
ll cnt[500005];
int main(){
	ll n,k;
	cin>>n>>k;
	ll ans=0;
	fep(i,k,1){
		cnt[i]=qpow(k/i,n);//gcd为i,2*i,3*i.....
		for(int j=2*i;j<=k;j+=i){//-gcd为2*i,3*i......
			cnt[i]-=cnt[j];
			cnt[i]+=mod;
			cnt[i]%=mod;
		}
		ans+=((ll)i*cnt[i])%mod;
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}