/*
* @author:  codancer
* @createTime:  2020-04-01, 17:40:20
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
	ll ans=0;
	ll n;
	scanf("%lld",&n);
	rep(b,n+1,2*n){
		if((n*b)%(b-n)==0){
			ll c=(n*b)/(b-n);
			printf("%lld\n",c^b);
			break;
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}