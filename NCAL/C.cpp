/*
* @author:  codancer
* @createTime:  2020-04-14, 19:05:15
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
vector<ll> sq;
void init(){
	for(ll i=0;i<=100000;i++){
		sq.pb(i*i);
	}
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while(T--){
		ll l,r;
		scanf("%lld %lld",&l,&r);
		ll x=lower_bound(sq.begin(),sq.end(),l)-sq.begin();
		ll y=upper_bound(sq.begin(),sq.end(),r)-sq.begin()-1;
		printf("%lld\n",y-x+1);
	}
	return 0;
}