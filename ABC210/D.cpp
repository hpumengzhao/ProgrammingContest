/*
* @author:  codancer
* @createTime:  2021-07-17, 20:58:58
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
const int N = 2001;
ll C;
ll solve(vector<vector<ll>> A){
	int H=A.size();
	int W=A[0].size();
	--H;--W;
	vector<vector<ll> > dp(H+1,vector<ll>(W+1,1e18));
	rep(i,1,H){
		rep(j,1,W){
			dp[i][j]=min({A[i][j],dp[i-1][j]+C,dp[i][j-1]+C});
		}
	}
	ll ans=1e18;
	rep(i,1,H){
		rep(j,1,W){
			ans=min({ans,dp[i-1][j]+C+A[i][j],dp[i][j-1]+C+A[i][j]});
		}
	}
	return ans;
}
int main(){
	int H,W;
	cin>>H>>W>>C;
	vector<vector<ll>> A(H+1,vector<ll>(W+1));
	rep(i,1,H){
		rep(j,1,W){
			cin>>A[i][j];
		}
	}
	ll ans=solve(A);
	rep(i,1,H){
		rep(j,1,W/2){
			swap(A[i][j],A[i][W+1-j]);
		}
	}
	ans=min(ans,solve(A));
	cout<<ans<<endl;
	return 0;
}