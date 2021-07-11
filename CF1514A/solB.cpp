/*
* @author:  codancer
* @createTime:  2021-07-03, 09:52:25
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
const int N = 4e5+100;
ll a[N],b[N],pos[N];
void solve(){
	int n;
	cin>>n;
	rep(i,1,n){
		cin>>a[i];
		b[i]=a[i];
		pos[a[i]]=i;
	}
	sort(a+1,a+n+1);
	vector<pair<int,int> > all;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]*a[j]>2*n){
				break;
			}else{
				all.push_back({a[i],a[j]});
			}
		}
	}
	int ans=0;
	for(auto v:all){
		int i=pos[v.first];
		int j=pos[v.second];
		if(b[i]*b[j]==i+j){
			++ans;
		}
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}