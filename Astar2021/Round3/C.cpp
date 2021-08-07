/*
* @author:  codancer
* @createTime:  2021-08-07, 16:16:49
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
int cal(int n){
	int ans=0;
	for(int i=0;i<(1<<(n-1));i++){
		set<int> pos;
		pos.insert(1);
		int now=1;
		for(int j=0;j<n-1;j++){
			if((i>>j)&1){//
				now=now+(j+1);
				now%=n;
				if(now==0) now=n;
				pos.insert(now);
			}else{
				now=now+(n-(j+1));
				now%=n;
				if(now==0) now=n;
				pos.insert(now);
			}
		}
		if(pos.size()==n) ++ans;
	}	
	return ans;
}
int main(){
	int n;
	cin>>n;
	rep(i,1,n){
		cout<<i<<":"<<cal(i)<<endl;
	}
	cout<<endl;
	return 0;
}