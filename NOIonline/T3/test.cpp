#include<bits/stdc++.h>

using namespace std;
typedef long long ll;


const long long mod = 998244353;
const int N = 2e5+100;
long long n,m,x,y;
long long fact[N],inv[N],factinv[N];
//
ll fa[N];
void dfs(int u,int f){
    fa[u]=f;
}
bool find(int x,int y){
    while(x!=0){
        if(fa[x]==y) return true;
        x=fa[x];
    }
    return false;
}
//
void init(){
    fact[0]=inv[1]=factinv[0]=inv[0]=fact[1]=factinv[1]=1;
    for(int j=2;j<=200010;j++){
        fact[j]=(fact[j-1]%mod*j%mod)%mod;
        inv[j]=(mod-mod/j)*inv[mod%j]%mod;
        factinv[j]=factinv[j-1]*inv[j]%mod;
    }
}
ll c(long long n,long long m){
    return fact[n]*factinv[m]%mod*factinv[n-m]%mod;
}

bool find2(int x,int y){
    while(x!=0){
        if(fa[x]==y) return true;
        x=fa[x];
    }
    return false;
}

ll call(long long n,long long m){
	if(m+n-1<n) return 0;
	return c(m+n-1,n);
}
void test(){
	init();
	cin>>m>>n>>x>>y;
	if(x>n){
		ll left=call(n,m);
		ll right=0;
		x=2*n+1-x;
		y=2*n+1-y;
		swap(x,y);
		for(ll j=1;j<=m;j++){
			ll xx=call(x-1,j);
			ll yy=call(n-y,m-j+1);
			right+=(xx*yy)%mod;
			right%=mod;
		}
		cout<<(left*right)%mod<<endl;
		return ;
	}
	if(y<=n){
		ll left=0;
		for(ll j=1;j<=m;j++){
			ll xx=call(x-1,j);
			ll yy=call(n-y,m-j+1);
			left+=(xx*yy)%mod;
			left%=mod;
		}
		long long right=call(n,m);
		cout<<(left*right)%mod<<endl;
		return ;
	}
	ll ans=0,left=0,right=0;
	y=2*n+1-y;
	for(ll j=1;j<=m;j++){
		left=call(x-1,j);left*=call(n-x,m-j+1);left%=mod;
		right=call(y-1,j);right*=call(n-y,m-j+1);right%=mod;
		ans+=(left*right)%mod;ans%=mod;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	test();
	return 0;
}
