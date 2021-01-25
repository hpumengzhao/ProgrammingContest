#include<bits/stdc++.h>

using namespace std;
const int N = 2e6+100;
const int mod = 1e9+7; 
typedef long long ll;
ll cnt[N];
void Fac(ll x){
	for(ll i=2;i*i<=x;i++){
		if(x%i==0){
			ll num=0;
			while(x%i==0){
				++num;
				x/=i;
			}
			cnt[i]=max(cnt[i],num);
		}
	}
	if(x!=1) cnt[x]=max(cnt[x],1LL);
}
ll Pow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1) ans=(ans*a)%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans%mod;
}
int main(){
	ll n;
	cin>>n;
	vector<ll> a(n+1);
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	} 
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans+=Pow(a[i],mod-2);
		ans%=mod;
	}
	for(int i=1;i<=n;i++){
		Fac(a[i]);
	}
	long long res=1;
	for(ll i=1;i<=1000000;i++){
		res*=Pow(i,cnt[i]);
		res%=mod;
	}
	cout<<(ans*res)%mod<<endl;
	return 0;
}
