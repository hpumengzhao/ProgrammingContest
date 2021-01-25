#include<bits/stdc++.h>
using namespace std;
const int N =  2e5+100;
struct DSU{
	int par[N];
	void init(){
		for(int i=1;i<=N-1;i++) par[i]=i;
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
}c[2];
bool ok(int a,int b){
	return abs(a-b)%2==0;
}
int a[N],b[N];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	c[0].init();c[1].init();
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	for(int i=2;i<=n;i++){
		if(ok(a[i],a[i-1])){
			c[0].unite(i,i-1);
		}
	}
	for(int i=2;i<=n;i++){
		if(ok(b[i],b[i-1])){
			c[1].unite(i,i-1);
		}
	}
	int x1,y1,x2,y2;
	while(m--){
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		if(c[0].same(x1,x2)&&c[1].same(y1,y2)){
			puts("YES");
		}else{
			puts("NO");
		}
	}
	return 0;
}
