/*
* @author:  codancer
* @createTime:  2020-04-10, 19:09:37
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
	ll n,m;
	scanf("%lld %lld",&n,&m);
	if(n==m){
		printf("%lld\n",n );
		return ;
	}
	if(n>m) swap(n,m);
	ll ans=0;
	while(1){
		if(n>m) swap(n,m);
		ll tmp=m-n;
		if(n>tmp){
			ans+=(n-tmp);
			m-=(n-tmp);
			n=tmp;
			break;
		}else{
			n*=2;
			ans++;
		}
	}
	if(n&&m) ans+=(1+m);
	printf("%lld\n",ans);
}
int main(){
	cout<<pow(3,12)*24<<endl;
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}