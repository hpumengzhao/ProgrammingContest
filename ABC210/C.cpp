/*
* @author:  codancer
* @createTime:  2021-07-17, 20:07:20
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
const int N = 3e5+100;
ll c[N];
map<ll,int> cnt;
int main(){
	int n,k;
	cin>>n>>k;
	rep(i,1,n) cin>>c[i],cnt[c[i]]=0;
	int ans=0;
	int now=0;
	rep(i,1,k){
		if(!cnt[c[i]]){
			++now;
			++ans;
		}
		++cnt[c[i]];
	}
	for(int i=k+1;i<=n;i++){
		cnt[c[i]]++;
		if(cnt[c[i]]==1){
			++now;
		}
		//cout<<i<<":"<<c[i]<<","<<c[i-k]<<' '<<cnt[c[i]]<<' '<<cnt[c[i-k]]<<' '<<now<<endl;
		if(cnt[c[i-k]]==1){
			--now;
		}
		cnt[c[i-k]]--;

		//cout<<i<<' '<<now<<endl;
		ans=max(ans,now);
	}
	cout<<ans<<endl;
	return 0;
}