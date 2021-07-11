/*
* @author:  codancer
* @createTime:  2021-07-03, 10:14:43
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
ll d[N],suf[N];
void solve(){
	int n;
	cin>>n;
	rep(i,1,n) cin>>d[i];
	sort(d+1,d+n+1);
	ll ans=d[n];
	suf[n]=d[n];
	for(int i=n-1;i>=1;i--){
		suf[i]=suf[i+1]+d[i];
	}
	for(ll i=1;i<n;i++){
		ans+=(n-i)*d[i]-suf[i+1];
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}