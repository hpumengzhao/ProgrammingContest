/*
* @author:  codancer
* @createTime:  2021-07-31, 14:25:41
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
void solve(int a,int b){
	if(a<=b) swap(a,b);
	if(a==b){
		if(a==1){
			puts("-1 -1");
		}else{
			printf("%d %d\n",2,b);
		}
		return ;
	}
	int dif=a-b;
	int minn=2e9;
	int maxx=-1;
	for(int c=1;c*c<=dif;c++){
		if(dif%c==0){
			if(a%c==b%c&&c!=1){
				minn=min(minn,c);
				maxx=max(maxx,c);
			}
			int p=dif/c;
			if(a%p==b%p&&p!=1){
				minn=min(minn,p);
				maxx=max(maxx,p);
			}			
		}
	}
	if(maxx==-1){
		puts("-1 -1");
	}else{
		printf("%d %d\n",minn,maxx);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	int a,b;
	while(T--){
		scanf("%d%d",&a,&b);
		solve(a,b);
	}
	return 0;
}