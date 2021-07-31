/*
* @author:  codancer
* @createTime:  2021-07-31, 15:15:26
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
const int N = 1e5+100;
int dp[N];
int u[N],v[N];
int ans[N];
vector<int> pos[N];
void solve(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n) dp[i]=1e9;
	dp[k]=0;
	rep(i,1,m){
		scanf("%d%d",&u[i],&v[i]);
		int fu=dp[u[i]];
		int fv=dp[v[i]];
		dp[u[i]]=min(fv,fu+1);
		dp[v[i]]=min(fu,fv+1);
	}
	rep(i,1,n){
		if(dp[i]==1e9) dp[i]=-1;
	}
	rep(i,1,n){
		printf("%d%c",dp[i],(i==n)?'\n':' ');
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}