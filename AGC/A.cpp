/*
* @author:  codancer
* @createTime:  2020-03-31, 19:08:04
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
const int N = 200;
ll dp[N][N];
char maze[N][N];
int main(){
	int n,m;
	cin>>n>>m;
	rep(i,1,n){
		rep(j,1,m){
			cin>>maze[i][j];
		}
	}
	rep(i,1,n){
		rep(j,1,m){
			dp[i][j]=1e9;
		}
	}
	if(maze[1][1]=='#'){
		dp[1][1]=1;
	}else{
		dp[1][1]=0;
	}
	rep(i,1,n){
		rep(j,1,m){
			if(i+1<=n) dp[i+1][j]=min(dp[i+1][j],dp[i][j]+(int)(maze[i][j]!=maze[i+1][j]));
			if(j+1<=m) dp[i][j+1]=min(dp[i][j+1],dp[i][j]+(int)(maze[i][j]!=maze[i][j+1]));
		}
	}
	cout<<(dp[n][m]+1)/2<<endl;
	return 0;
}