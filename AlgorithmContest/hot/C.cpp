/*
* @author:  codancer
* @createTime:  2020-04-03, 14:25:05
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 19961993;
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define fep(i,a,b) for(int i=(a);i>=(b);i--)
typedef vector<int> VI;
typedef vector<ll> VII;
typedef pair<int,int> pii;
vector<ll> prim;
ll pos[300];
bool ok(ll x){
	if(x<=1){
		return 0;
	}
	if(x==2){
		return 1;
	}
	for(ll i=2;i*i<=x;i++){
		if(x%i==0){
			return 0;
		}
	}
	return 1;
}
void init(){
	for(ll i=2;i<=300;i++){
		if(ok(i)){
			prim.pb(i);
		}
	}
	for(int i=0;i<60;i++){
		pos[prim[i]]=i;
	}
}
struct BIT{
	ll c[100005];
	void init(){
		memset(c,0,sizeof(c));
	}
	ll lowbit(ll x){
		return (x&(-x));
	}
	void update(ll id,ll x){
		for(ll i=id;i<=100001;i+=lowbit(i)){
			c[i]+=x;
		}
	}
	ll pre(ll id){
		ll ans=0;
		for(ll i=id;i;i-=lowbit(i)){
			ans+=c[i];
		}
		return ans;
	}
	ll query(ll a,ll b){
		return pre(b)-pre(a-1);
	}
}A[63];
ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1) ans=(ans%mod*a%mod)%mod;
		a=a%mod*a%mod;
		a%=mod;
		b>>=1;
	}
	return ans%mod;
}
ll lst[100005];
int main(){
	init();
	for(int i=0;i<60;i++) A[i].init();
	for(int i=1;i<=100000;i++) lst[i]=3;
	for(int i=1;i<=100000;i++) A[1].update(i,1);
	int n;
	scanf("%d",&n);
	rep(i,1,n){
		ll a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		if(a==0){
			ll ans=1;
			rep(j,0,59){
				ll num=A[j].query(b,c);
				if(num>0){
					ans*=(prim[j]-1)*qpow(prim[j],num-1);
					ans%=mod;
				}
			}
			printf("%lld\n", ans);
		}else{
			ll now=lst[b];
			lst[b]=c;
			for(ll v:prim){
				if(now%v==0){
					ll cnt=0;
					while(now%v==0){
						now/=v;
						++cnt;
					}
					A[pos[v]].update(b,-cnt);
				}
			}
			for(ll v:prim){
				if(c%v==0){
					ll cnt=0;
					while(c%v==0){
						c/=v;
						++cnt;
					}
					A[pos[v]].update(b,cnt);
				}
			}
		}
	}
	return 0;
}