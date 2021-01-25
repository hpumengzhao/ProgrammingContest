/*
* @author:  codancer
* @createTime:  2020-04-05, 13:46:51
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
const int N = 300000;
vector<int> G[N];
ll f[N][3];
ll node[N];
bool vis[N];
void dfs(int u,int fa){
	for(int v:G[u]){
		if(v==fa) continue;
		dfs(v,u);
		if(f[u][0]<=f[v][0]+1){
			f[u][1]=f[u][0];
			f[u][0]=f[v][0]+1;
			node[u]=v;
		}else if(f[u][1]<f[v][0]+1){
			f[u][1]=f[v][0]+1;
		}
	}
}
void dfs2(int u,int fa){
	for(int v:G[u]){
		if(v==fa) continue;
		if(node[u]==v){
			f[v][2]=max(f[u][2],f[u][1])+1;
		}else{
			f[v][2]=max(f[u][2],f[u][0])+1;
		}
		dfs2(v,u);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	vector<ll> w(n+1);
	rep(i,1,n){
		scanf("%lld",&w[i]);
	}
	int u,v;
	rep(i,1,n-1){
		scanf("%d %d",&u,&v);
		G[v].pb(u);
		G[u].pb(v);
	}
	dfs(1,-1);
	dfs2(1,-1);
	ll ans=0;
	rep(i,1,n){
		ans=max(ans,w[i]*max(f[i][2],f[i][0]));
	}
	cout<<ans<<endl;
	return 0;
}