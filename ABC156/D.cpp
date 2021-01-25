/*
* @author:  codancer
* @createTime:  2020-02-22, 20:13:02
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
ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans%mod;
}
void sub(long long &a,long long b){
	a-=b;
	if(a<0) a+=mod;
	a%=mod;
}
long long C(long long n,long long m){
	long long ansa=1,ansb=1;
	for(ll i=n-m+1;i<=n;i++) ansa=ansa*i%mod;
	for(ll i=1;i<=m;i++) ansb=ansb*i%mod;
	return (ansa%mod*qpow(ansb,mod-2))%mod;
}
int main(){
	long long n,a,b;
	cin>>n>>a>>b;
	long long res=qpow(2,n);
	sub(res,1);
	sub(res,C(n,a));
	sub(res,C(n,b));
	cout<<res<<endl;
	return 0;
}