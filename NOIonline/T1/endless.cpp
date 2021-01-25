/*
* @author:  codancer
* @createTime:  time
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
const int N = 2e5+100;
ll n,L,v,a[N],q,tt,predis[N];

bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	// freopen("endless.in","r",stdin);
	// freopen("endless.out","w",stdout);
	scanf("%lld %lld %lld",&n,&L,&v);
	rep(i,1,n){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	rep(i,1,n) predis[i]=predis[i-1]+a[i];
	scanf("%lld",&q);
	while(q--){
		scanf("%lld",&tt);
		ll l=0;
		ll r=n+1;
		bool ok=0;
		rep(i,1,30){
			ll mid=(l+r)/2;
			if(predis[mid]+L>tt*v){
				r=mid;
				ok=1;
			}else{
				l=mid;
			}
		}
		if(ok){
			printf("%lld\n",r);
		}else{
			puts("-1");
		}
	}
	return 0;
}