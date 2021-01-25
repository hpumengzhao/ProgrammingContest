/*
* @author:  codancer
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
#define pb push_back
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef pair<int,int> pii;
const int N = 2e5+100;
int par[N],siz[N];
void init(int n){
	for(int i=1;i<=n;i++){
		par[i]=i;
		siz[i]=1;
	}
}
int find(int x){
	return x==par[x]?x:par[x]=find(par[x]);
}
void unite(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y) return ;
	par[x]=y;
	siz[y]+=siz[x];
	siz[x]=0;
}
bool same(int x,int y){
	return find(x)==find(y); 
}
int adj[N];
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	init(n);
	int u,v; 
	vector<int> ans(n+1);
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		adj[u]++;
		adj[v]++;
		if(!same(u,v)){
			unite(u,v);
		}
	}
	for(int i=1;i<=n;i++){
		ans[i]=siz[find(i)]-adj[i]-1;
	}
	for(int i=1;i<=k;i++){
		cin>>u>>v;
		if(find(u)==find(v)){
			ans[u]--;
			ans[v]--;
		}
	}
	cout<<ans[1];
	for(int i=2;i<=n;i++){
		cout<<' '<<ans[i];
	}
	cout<<endl;
	return 0;
}

