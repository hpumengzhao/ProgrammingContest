/*
* @author:  codancer
* @createTime:  2020-04-25, 19:53:21
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
const int N = 2e5+100;
int u[N],v[N];
map<int,int> fa,siz;
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void unite(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y) return ;
	fa[x]=y;
	siz[y]+=siz[x];
	siz[x]=0;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		fa.clear();
		siz.clear();
		set<int> st;
		rep(i,1,n){
			scanf("%d %d",&u[i],&v[i]);
			st.insert(u[i]);
			st.insert(v[i]);
		}
		for(int v:st){
			fa[v]=v;
			siz[v]=1;
		}
		rep(i,1,n){
			unite(u[i],v[i]);
		}
		int ans=0;
		for(int v:st){
			ans=max(ans,siz[v]);
		}
		printf("%d\n", ans);
	}
	return 0;
}