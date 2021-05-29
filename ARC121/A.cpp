/*
* @author:  codancer
* @createTime:  2021-05-29, 19:41:34
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
const int N = 2e5+100;
struct node{
	ll x,y;
	int id;
}a[N],b[N];
bool cmp1(node a,node b){
	return a.x<b.x;
}
bool cmp2(node a,node b){
	return a.y<b.y;
}
ll dis(node a,node b){
	return max(abs(a.x-b.x),abs(a.y-b.y));
}
int main(){
	int n;
	cin>>n;
	rep(i,1,n){
		cin>>a[i].x>>a[i].y;
		b[i]=a[i];
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp1);
	set<int> ids;
	rep(i,1,2) ids.insert(a[i].id);
	fep(i,n,n-1) ids.insert(a[i].id);
	sort(a+1,a+n+1,cmp2);
	rep(i,1,2) ids.insert(a[i].id);
	fep(i,n,n-1) ids.insert(a[i].id);
	vector<ll> all;
	VI idd;
	for(int v:ids) idd.pb(v);
	int siz=(int)idd.size();
	for(int i=1;i<siz;i++){
		for(int j=0;j<i;j++){
			all.push_back(dis(b[idd[i]],b[idd[j]]));
		}
	}
	sort(all.begin(),all.end());
	cout<<all[(int)all.size()-2]<<endl;
	return 0;
}