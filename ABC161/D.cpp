/*
* @author:  codancer
* @createTime:  2020-04-04, 20:14:09
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
set<ll> all;
void dfs(ll now){
	if(now>3234566667) return ;
	// cout<<now<<endl;
	if(all.size()>300000){
		return ;
	}
	all.insert(now);
	ll x=now%10;
	if(x>=1){
		dfs(now*10+(x-1));
	}
	if(x+1<=9){
		dfs(now*10+x+1);
	}
	dfs(now*10+x);
}
int main(){
	int k;
	cin>>k;
	rep(i,1,9){
		dfs(i);
	}
	VII a;
	for(ll v:all){
		a.pb(v);
	}
	cout<<a[k-1]<<endl;
	return 0;
}