#include<bits/stdc++.h>

using namespace std;
const int maxn = 30;
typedef long long ll;
ll dp[maxn][maxn];
bool vis[maxn][maxn];
ll dir[8][2]={{-2,1},{-1,2},{1,2},{2,1},{1,-2},{2,-1},{-2,-1},{-1,-2}};
int main(){
	memset(vis,0,sizeof(vis));
	ll n,m;
	ll x,y;
	cin>>n>>m>>x>>y;
	vis[x][y]=1;
	for(ll i=0;i<8;i++){
		ll dx=x+dir[i][0];
		ll dy=y+dir[i][1];
		if(dx>=0&&dy>=0) vis[dx][dy]=1;
	}
	for(ll i=0;i<=n;i++){
		if(!vis[i][0]) dp[i][0]=1;
		else break;
	}
	for(ll i=0;i<=m;i++){
		if(!vis[0][i]) dp[0][i]=1;
		else break;
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(!vis[i][j]){
				dp[i][j]+=(dp[i-1][j]+dp[i][j-1]);
			}
			else dp[i][j]=0;
		}
	}
	cout<<dp[n][m]<<endl;
	return 0;
} 