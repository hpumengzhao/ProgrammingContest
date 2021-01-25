/*
* @author:  codancer
* @createTime:  2020-04-18, 19:05:43
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
ll a[300000];
void solve(){
	ll n,k;
	scanf("%lld %lld",&n,&k);
	rep(i,1,n){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	int l=1;int r=n+1;
	for(int tt=1;tt<=50;tt++){
		int mid=(l+r)>>1;
		bool ok=0;
		for(int i=mid;i<=n;i++){
			if(a[i]-a[i-mid+1]<=k){
				ok=1;
				break;
			}
		}
		if(ok){
			l=mid;
		}else r=mid;
	}
	printf("%d\n",l);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}