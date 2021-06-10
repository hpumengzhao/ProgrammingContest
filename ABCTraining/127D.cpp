/*
* @author:  codancer
* @createTime:  2021-06-07, 19:29:19
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
struct node{
	int B,C;
};
bool cmp(node a,node b){
	return a.C>b.C;
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	vector<node> b(m);
	rep(i,0,n-1) cin>>a[i];
	sort(a.begin(),a.end());
	rep(i,0,m-1) cin>>b[i].B>>b[i].C;
	sort(b.begin(),b.end(),cmp);
	int id=0;
	for(int i=0;i<n;i++){
		if(id>=m) break;
		if(b[id].B){
			if(a[i]<b[id].C){
				a[i]=b[id].C;
				--b[id].B;
			}else{
				break;
			}
			if(b[id].B==0) ++id;
		}
	}
	ll ans=0;
	for(int v:a) ans+=v;
	cout<<ans<<endl;
	return 0;
}