/*
* @author:  codancer
* @createTime:  2021-07-20, 11:57:05
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
ll a[N],b[N];
ll sa,sb;
int n;
bool check(ll k){
	ll A=sa+k*100;
	ll B=sb;
	ll del=min(n*1LL,(n+k)/4);
	rep(i,1,del){
		A-=a[i];
	}
	if(k<del){
		rep(i,1,del-k) B-=b[i];
	}
	return A>=B;
}
void solve(){
	cin>>n;
	sa=sb=0;
	rep(i,1,n) cin>>a[i],sa+=a[i];
	rep(i,1,n) cin>>b[i],sb+=b[i];
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	ll l=0,r=1e9;
	rep(steps,1,35){
		ll mid=(l+r)>>1;
		if(check(mid)){
			r=mid;
		}else{
			l=mid;
		}
	}
	cout<<r<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}