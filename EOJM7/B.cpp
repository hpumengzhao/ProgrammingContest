/*
* @author:  codancer
* @createTime:  2021-07-10, 19:40:43
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
const int N = 1e5+100;
vector<int> h;
int n;
int ST[N][22];
void init(int n){
	rep(i,1,n) ST[i][0]=h[i];
	for(int j=1;(1<<j)<=n;j++){
		for(int i=0;i+(1<<j)-1<=n;i++){
			ST[i][j]=max(ST[i][j-1],ST[i+(1<<(j-1))][j-1]);
		}
	}
}
int query(int l,int r){
	int k=log2(r-l+1);
	return max(ST[l][k],ST[r-(1<<k)+1][k]);
}
int solve(vector<int> h){
	init(n);
	vector<int> inc(n+1);
	inc[1]=1;
	for(int i=2;i<=n;i++){
		if(h[i]>h[i-1]){
			inc[i]=inc[i-1];
		}else{
			inc[i]=i;
		}
	}
	int l=0,r=n+1;
	bool flag=0;
	rep(steps,1,35){
		int mid=(l+r)>>1;
		if(mid==0) return 0;
		bool fd=0;
		for(int i=2*mid;i<=n;i++){
			if(i-inc[i]+1>=mid&&query(i-2*mid+1,i-mid)<h[i-mid+1]){
				fd=1;break;
			}
		}
		if(fd){
			flag=1;
			l=mid;
		}else{
			r=mid;
		}
	}
	if(flag){
		return l;
	}
	return 0;
}
int main(){
	cin>>n;
	h.resize(n+1);
	rep(i,1,n) cin>>h[i];
	int ans=solve(h);
	for(int i=1;i<=n/2;i++){
		swap(h[i],h[n+1-i]);
	}
	ans=max(ans,solve(h));
	cout<<2*ans<<endl;
	return 0;
}