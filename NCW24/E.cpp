/*
* @author:  codancer
* @createTime:  2020-04-10, 20:13:32
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
const int N = 1000010;
struct node{
	int id;
	ll dis;
};
int n,m,u,v,x;
ll w;
bool operator<(node a,node b){
	return a.dis>b.dis;
}
struct graphs{
	vector<pair<int,ll>> G[N];
	void addedge(int u,int v,ll w){
		G[u].pb({v,w});
	}
	ll dis[N];
	priority_queue<node> q;
	bool vis[N];
	void bfs(int st){
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			dis[i]=1e17;
		}
		dis[st]=0;
		q.push({st,0});
		while(!q.empty()){
			node rt=q.top();q.pop();
			int u=rt.id;
			if(vis[u]) continue;
			vis[u]=1;
			for(auto adj:G[u]){
				int v=adj.first;
				ll w=adj.second;
				if(dis[v]>dis[u]+w){
					dis[v]=dis[u]+w;
					q.push({v,dis[v]});
				}
			}
		}
	}
}A,B;
pair<pair<int,int>,ll> edges[N];
int par[1000000];
void init(int n){
	for(int i=1;i<=n;i++) par[i]=i;
}
int find(int x){
	return par[x]==x?x:par[x]=find(par[x]);
}
void unite(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y) return ;
	par[x]=y;
}

int main(){
	scanf("%d %d",&n,&m);
	rep(i,1,m){
		scanf("%d %d %lld",&u,&v,&w);
		edges[i]={{u,v},w};
		A.addedge(u,v,w);
		A.addedge(v,u,w);
		B.addedge(v,u,w);
		B.addedge(u,v,w);
	}
	init(n);
	A.bfs(1);
	B.bfs(n);
	ll sp=A.dis[n];
	for(int i=1;i<=m;i++){
		int x=edges[i].first.first;
		int y=edges[i].first.second;
		if(A.dis[x]+B.dis[y]+edges[i].second==sp||A.dis[y]+B.dis[x]+edges[i].second==sp){
			continue;
		}
		unite(x,y);
	}
	int ck=0;
	rep(i,1,n){
		if(par[i]==i){
			++ck;
		}
	}
	if(ck>1){
		puts("NO");
	}else{
		puts("YES");
	}
	return 0;
}