/*
* @author:  codancer
* @createTime:  2021-07-10, 19:00:40
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
bool tri(int x,int y,int z){
	return (x+y>z)&&(x+z>y)&&(y+z>x);
}
int main(){
	vector<int> a(4);
	for(int i=0;i<4;i++) cin>>a[i];
	sort(a.begin(),a.end());
	if((a[0]>a[3]-a[2]-a[1])&&a[0]!=0&&a[1]!=0&&a[2]!=0&&a[3]!=0){
		cout<<"quadrangle"<<endl;
		return 0;
	}
	for(int i=0;i<4;i++){
		VI l;
		for(int j=0;j<4;j++){
			if(j!=i){
				l.pb(a[j]);
			}
		}
		if(tri(l[0],l[1],l[2])){
			cout<<"triangle"<<endl;
			return 0;
		}
	}
	cout<<"Impossible"<<endl;
	return 0;
}