/*
* @author:  codancer
* @createTime:  2021-07-18, 20:18:42
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
ll a[N],b[N],c[N];
int main(){
	int n;
	cin>>n;
	rep(i,1,n){
		cin>>a[i];
	}
	rep(i,1,n){
		cin>>b[i];
	}
	rep(i,1,n){
		cin>>c[i];
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	sort(c+1,c+n+1);
	int pa=1;
	int pc=1;
	int ans=0;
	rep(i,1,n){
		// cout<<i<<' '<<pa<<' '<<pc<<endl;
		while(c[pc]<=b[i]&&pc<=n){
				++pc;
		}
		if(pa<=n&&pc<=n&&a[pa]<b[i]&&b[i]<c[pc]){
			++ans;
			++pa;
			++pc;
		}
	}
	cout<<ans<<endl;
	return 0;
}