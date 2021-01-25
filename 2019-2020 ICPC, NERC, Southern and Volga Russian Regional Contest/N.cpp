#include<bits/stdc++.h>

using namespace std;
const int N = 2e5+100;
unordered_map<int,int> ind,edgeid,par,vis,res;
int x[N],y[N];
vector<int> Point;
set<int> all;
void init(){
	res.clear();
	par.clear();
	ind.clear();
	edgeid.clear();
	vis.clear();
	Point.clear();
	all.clear();
}
int find(int x){
	return x==par[x]?x:par[x]=find(par[x]);
}
void unite(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y) return ;
	par[x]=y;
}
bool same(int x,int y){
	return find(x)==find(y);
}
int main(){
	int T,n;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		init();
		for(int i=1;i<=n;i++){
			scanf("%d %d",&x[i],&y[i]);
			par[x[i]]=x[i];
			par[y[i]]=y[i];
			ind[x[i]]++;
			ind[y[i]]++;
			edgeid[x[i]]=i;
			edgeid[y[i]]=i;
			all.insert(x[i]);
			all.insert(y[i]);
		}
		for(int i=1;i<=n;i++){
			if(!same(x[i],y[i])) unite(x[i],y[i]);
			else{
				res[x[i]]=res[y[i]]=1;
				edgeid[x[i]]=i;
				edgeid[y[i]]=i;
			}
		}
		for(int v:all){
			if(ind[v]==1&&!vis[find(v)]){
				Point.push_back(v);
				vis[find(v)]=1;				
			}
		}
		for(int v:all){
			if((res[v])&&!vis[find(v)]){
				Point.push_back(v);
				vis[find(v)]=1;
			}
		}
		int siz=(int)Point.size();
		printf("%d\n",siz-1);
		for(int i=0;i<siz-1;i++){
			printf("%d %d %d\n",edgeid[Point[i]],Point[i],Point[siz-1]);
		}
	}
	return 0;
}
