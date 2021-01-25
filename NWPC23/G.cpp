/*
* @author:  codancer
* @createTime:  time
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
ll siz[N];
vector<int> G[N];
void dfs(int u,int fa){
	siz[u]=1;
	for(int v:G[u]){
		if(v==fa){
			continue;
		}
		dfs(v,u);
		siz[u]+=siz[v];
	}
}
int main(){
	int n,u,v;
	cin>>n;
	rep(i,1,n-1){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1,0);
	vector<ll> wei;
	rep(i,2,n){
		wei.pb((n-siz[i])*siz[i]);
		// cout<<i<<' '<<siz[i]<<endl; 
	}
	sort(wei.begin(),wei.end(),greater<ll>());
	long long ans=0;
	for(ll i=0;i<n-1;i++){
		ans+=(i+1)*wei[i];
	}
	cout<<ans<<endl;
	return 0;
}