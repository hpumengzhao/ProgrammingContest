/*
* @author:  codancer
* @createTime:  2021-08-07, 14:01:19
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
void solve(){
	int n,a,b,c;
	cin>>n>>a>>b>>c;
	if(n==1){
		if(a!=b||a!=c||b!=c){
			cout<<"no"<<endl;
			return ;
		}
		cout<<"yes"<<endl;
	}else{
		if(c>=b&&c<=a){
			int tot=n*c;
			int res=tot-a-b;
			if((n-2)*b<=res&&res<=(n-2)*a){
				cout<<"yes"<<endl;
				return ;
			}else{
				cout<<"no"<<endl;
				return ;
			}
		}
		else cout<<"no"<<endl;
		return ;
	}
}
int main(){
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}