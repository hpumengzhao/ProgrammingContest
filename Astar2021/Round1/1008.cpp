/*
* @author:  codancer
* @createTime:  2021-07-31, 14:50:25
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
const int N = 55;
int s[N];
int kill[N][N];
bool death[N];
void solve(){
	int n;
	cin>>n;
	rep(i,1,n) cin>>s[i];
	int wolf=-1;
	rep(i,1,n) death[i]=0;
	rep(i,1,n){
		rep(j,1,n){
			cin>>kill[i][j];
		}
	}
	rep(i,1,n){
		if(s[i]){
			wolf=i;break;
		}
	}
	int now_death = kill[wolf][1];
	death[now_death]=1;
	int live=n-1;//还剩下n-1玩家
	while(1){
		if(now_death==wolf){
			cout<<"lieren"<<'\n';
			return ;
		}
		if(live==2&&death[wolf]==0){
			cout<<"langren"<<'\n';
			return ;
		}
		rep(j,1,n){
			if(death[kill[now_death][j]]==0){
				now_death=kill[now_death][j];
				death[now_death]=1;
				--live;
				break;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}