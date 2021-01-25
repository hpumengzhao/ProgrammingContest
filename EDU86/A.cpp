/*
* @author:  codancer
* @createTime:  2020-04-26, 22:31:52
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
void solve(){
	ll x,y,a,b;
	scanf("%lld%lld%lld%lld",&x,&y,&a,&b);
	ll ans=abs(x-y)*a+min(x,y)*b;
	if(x>0&&y>0) ans=min(ans,abs(x-y)*a+min(x,y)*2*a);
	printf("%lld\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}