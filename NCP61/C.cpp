/*
* @author:  codancer
* @createTime:  2020-04-11, 10:41:26
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
int a[4],b[4],m,u,v;
vector<int> sb;
int ans=0;
int siz=0;
void dfs(int id){
	if(id==(int)sb.size()){
		rep(i,0,3){
			if(a[i]!=b[i]) return ;
		}
		++ans;
		return ;
	}
	rep(i,0,3){
		b[i]+=sb[id];
		dfs(id+1);
		b[i]-=sb[id];
	}
}
bool vis[20];
vector<int> G[20];
void dfs1(int u){
	if(vis[u]) return ;
	vis[u]=1;
	++siz;
	for(int v:G[u]){
		dfs1(v);
	}
}
int main(){
	rep(i,0,3) scanf("%d",&a[i]);
	memset(b,0,sizeof(b));
	scanf("%d",&m);
	rep(i,1,m){
		scanf("%d%d",&u,&v);
		G[u].pb(v);
		G[v].pb(u);
	}
	for(int i=1;i<=12;i++){
		if(!vis[i]){
			dfs1(i);
			sb.pb(siz);
			siz=0;
		}
	}
	dfs(0);
	printf("%d\n", ans);
	return 0;
}