/*
* @author:  codancer
* @createTime:  2021-06-09, 20:24:32
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
const ll mod = 1000003;
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
const int N = 333;

ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
ll a[N];
ll pre[N];
ll dp[N][N];
ll val[N][N];
int getMulti(int l,int r){
	return (pre[r]*qpow(pre[l-1],mod-2))%mod;
}
int main(){
	int n;
	cin>>n;
	pre[0]=1;
	rep(i,1,n){
		cin>>a[i];
		pre[i]=pre[i-1]*a[i];
		pre[i]%=mod;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			val[i][j]=getMulti(i,j);
		}
	}
	for(int len=1;len<=n;len++){
		for(int i=1;i<n;i++){
			int j=i+len-1;
			for(int k=i;k<j&&k<n;k++){
				ll x=val[i][k];
				ll y=val[k+1][j];
				dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+(x-y)*(x-y));
			}
		}
	}
	cout<<dp[1][n]<<endl;
	return 0;
}