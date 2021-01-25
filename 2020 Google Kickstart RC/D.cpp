/*
* @author:  codancer
* @createTime:  2020-05-20, 08:21:40
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
const int N = 2e6+100;
struct BIT{
	ll c[N];
	int lowbit(int x){
		return x&(-x);
	}
	void update(int pos,ll x){
		for(int i=pos;i<=N-100;i+=lowbit(i)){
			c[i]+=x;
		}
	}
	ll query(int pos){
		ll ans=0;
		for(int i=pos;i;i-=lowbit(i)){
			ans+=c[i];
		}
		return ans;
	}
	ll get(int l,int r){
		return query(r)-query(l-1);
	}
}T1,T2;
void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,N-100) T1.c[i]=T2.c[i]=0;
	vector<int> a(n+1);
	rep(i,1,n){
		 scanf("%d",&a[i]);
		 if(i&1) T1.update(i,i*a[i]);
		 else T1.update(i,-i*a[i]);
		 if(i&1) T2.update(i,a[i]);
		 else T2.update(i,-a[i]);
	}
	char op[2];
	int u,v;
	ll ans=0;
	rep(i,1,m){
		scanf("%s %d %d",op,&u,&v);
		if(op[0]=='U'){
			if(u&1) T1.update(u,u*v-u*a[u]);
			else T1.update(u,-u*v+u*a[u]);
			if(u&1) T2.update(u,v-a[u]);
			else T2.update(u,-v+a[u]);
			a[u]=v;
		}else{
			if(u&1){
				ans+=T1.get(u,v)-(u-1)*T2.get(u,v);
			}else{
				ans+=-T1.get(u,v)+(u-1)*T2.get(u,v);
			}
		}
	}
	printf("%lld\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	rep(tt,1,T){
		printf("Case #%d: ",tt);
		solve();
	}
	return 0;
}
