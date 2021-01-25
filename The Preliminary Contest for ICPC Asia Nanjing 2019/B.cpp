#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+100;
const int mod = 1e9+7;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f3f;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define fep(i,a,b) for(int i=(a);i>=(b);i--)
inline bool read(ll &num) {
	char in;bool IsN=false;
	in=getchar();
	if(in==EOF) return false;
	while(in!='-'&&(in<'0'||in>'9')) in=getchar();
	if(in=='-'){ IsN=true;num=0;}
	else num=in-'0';
	while(in=getchar(),in>='0'&&in<='9'){
			num*=10,num+=in-'0';
	} 
	if(IsN) num=-num;
	return true;
}
ll ph[N];
void init(){
	rep(i,1,N-10){
		ph[i]=i;
	}
	rep(i,2,N-10){
		if(ph[i]==i){
			for(int j=i;j<=N-10;j+=i){
				ph[j]=ph[j]/i*(i-1);
			}
		}
	}
}
ll qpow(ll a,ll b,ll mod){
	ll ans=1;
	while(b){
		if(b&1) ans=(ans%mod*a%mod)%mod;
		a=(a%mod*a%mod)%mod;
		b>>=1;
	}
	return ans%mod;
}
bool check(ll a,ll b,ll m){
	if(b==0) return 1>=ph[m];
	if(b==1) return a>=ph[m];
	ll ans=1;
	if(ans>=ph[m]) return 1;
	rep(i,1,b-1){
		rep(j,1,a){
			ans*=a;
			if(ans>=ph[m]) return 1;
		}
	}
	return 0;
}
ll  solve(ll a,ll b,ll m){
	if(m==1) return 0;
	if(b==0) return 1%m;
	if(b==1) return a%m;
	if(__gcd(a,m)==1){
		return qpow(a,solve(a,b-1,ph[m]),m);
	}
	else{
		if(check(a,b-1,m)){
			return qpow(a,solve(a,b-1,ph[m])+ph[m],m);
		}
		else return qpow(a,solve(a,b-1,m),m);
	}
}
ll T,a,b,m;
int main(){
	//freopen("1.in", "r", stdin);
	read(T);
	init();
	//cout<<ph[1000000]<<endl;
	while(T--){
		read(a);read(b);read(m);
		printf("%lld\n",solve(a,b,m)%m);
	}
	return 0;
}
