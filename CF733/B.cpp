/*
* @author:  codancer
* @createTime:  2021-07-20, 11:42:13
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9+7;
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define fep(i,a,b) for(int i=(a);i>=(b);i--)
#define deb(x) cerr<<#x<<" = "<<(x)<<"\n"
typedef vector<int> VI;
typedef vector<ll> VII;
typedef pair<int,int> pii;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll Rand(ll B) {
	return (ull)rng() % B;
}
int dir[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int> > maze(n+1,vector<int>(m+1,0));
	maze[1][1]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==1&&j==1) continue;
			if(i>1&&i<n&&j>1&&j<m) continue;
			bool ok=1;
			for(int k=0;k<8;k++){
				int x=i+dir[k][0];
				int y=j+dir[k][1];
				if(x>=1&&x<=n&&y>=1&&y<=m&&maze[x][y]==1){
					ok=0;break;
				}
			}
			if(ok) maze[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<maze[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}