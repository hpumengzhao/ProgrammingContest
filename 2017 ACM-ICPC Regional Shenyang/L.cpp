#include<bits/stdc++.h>

using namespace std;
const int N = 1e6+100;
vector<int> G[N];
int siz[N];
void dfs(int u,int fa){
	siz[u]=1;
	for(int v:G[u]){
		if(v==fa) continue;
		dfs(v,u);
		siz[u]+=siz[v];
	}
}
int u,v;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n,k;
		int ans=0;
		int u,v;
		scanf("%d %d",&n,&k);
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=1;i<=n-1;i++){
			scanf("%d %d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1,0);
		for(int i=1;i<=n;i++){
			if(siz[i]>=k&&n-siz[i]>=k) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
