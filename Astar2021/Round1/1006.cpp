/*
* @author:  codancer
* @createTime:  2021-07-31, 14:01:52
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
const int N = 5e6+100;
bool pos[N];
struct UF{
	int fa[N];
	int siz[N];
	void init(int n){
		rep(i,0,n){
			 fa[i]=i;
			 siz[i]=1;
		}
	}
	int find(int x){
		return x==fa[x]?x:fa[x]=find(fa[x]);
	}
	void unite(int x,int y){
		x=find(x);
		y=find(y);
		if(x==y) return ;
		fa[x]=y;
		siz[y]+=siz[x];
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
}uf;
int main(){
	int n;
	scanf("%d",&n);
	uf.init(n);
	int a,b;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a,&b);
		if(a==1){
			pos[b]=1;
			if(b==1){
				uf.unite(0,1);
			}else{
				if(pos[b-1]) uf.unite(b,b-1);
			}
			if(b+1<=n&&pos[b+1]){
				uf.unite(b,b+1);
			}
		}else{
			int rt=uf.siz[uf.find(0)];
			if(rt==b){
				if(b+1<=n&&pos[b+1]==0){
					printf("%d\n",rt+1);
				}else if(b+1<=n&&pos[b+1]){
					printf("%d\n",rt+1+uf.siz[uf.find(b+1)]);
				}
			}else{
				printf("%d\n",rt);
			}
		}
	}
	return 0;
}