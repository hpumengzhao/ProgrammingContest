/*
* @author:  codancer
* @createTime:  2020-05-04, 20:44:59
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll inf = 1e18;
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
vector<int> G[N];
ll dp[N],w[N],ans[N];
int n;
void dfs(int u,int fa){
	int x=lower_bound(dp,dp+n,w[u])-dp;
	ll val=dp[x];
	dp[x]=w[u];
	ans[u]=lower_bound(dp,dp+n,inf)-dp;
	for(int v:G[u]){
		if(v==fa) continue;
		dfs(v,u);
	}
	dp[x]=val;
}
int main(){
	cin>>n;
	rep(i,0,n)dp[i]=inf;
	rep(i,0,n-1){
		cin>>w[i];
	}
	int u,v;
	rep(i,1,n-1){
		cin>>u>>v;
		--u;
		--v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(0,-1);
	rep(i,0,n-1) cout<<ans[i]<<endl;
	return 0;
}