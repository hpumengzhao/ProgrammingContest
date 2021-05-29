/*
* @author:  codancer
* @createTime:  2021-05-29, 20:56:36
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


const int N = 3e5+100;
bool odd(int x){
	return x%2==0;
}
vector<ll> G[3];
ll Gao(vector<ll> a,vector<ll> b){
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	ll ans=1e18;
	int n=(int)a.size();
	int m=(int)b.size();
	for(int i=0;i<n;i++){//拿a[i]的话
		int l=lower_bound(b.begin(),b.end(),a[i])-b.begin();
		for(int j=max(0,l-1);j<=min(m-1,l+1);j++){
			ans=min(ans,abs(a[i]-b[j]));
		}
	}
	return ans;
}
ll Gao2(vector<ll> A,vector<ll> B,vector<ll> C){
	int x=(int)A.size();
	int y=(int)B.size();
	int z=(int)C.size();
	vector<pair<ll,int> > ans0(x);
	vector<pair<ll,int> > ans1(x);
	for(int i=0;i<x;i++){
		ll minn=1e18;
		int l=lower_bound(B.begin(),B.end(),A[i])-B.begin();
		if(l<y) minn=min(minn,B[l]-A[i]);
		if(l) minn=min(minn,A[i]-B[l-1]);
		ans0[i].fi=minn;
		ans0[i].se=i;
	}
	for(int i=0;i<x;i++){
		ll minn=1e18;
		int l=lower_bound(C.begin(),C.end(),A[i])-C.begin();
		if(l<z) minn=min(minn,C[l]-A[i]);
		if(l) minn=min(minn,A[i]-C[l-1]);
		ans1[i].fi=minn;
		ans1[i].se=i;
	}
	sort(ans0.begin(),ans0.end());
	sort(ans1.begin(),ans1.end());
	int minn=0;
	if(ans0[0].se!=ans1[0].se){
		return ans0[0].fi+ans1[0].fi;
	}else{
		return min(ans0[0].fi+ans1[1].fi,ans0[1].fi+ans1[0].fi);
	}
}
int main(){
	int n;
	cin>>n;
	ll x;
	char c;
	rep(i,1,2*n){
		cin>>x>>c;
		if(c=='R') G[0].pb(x);
		if(c=='G') G[1].pb(x);
		if(c=='B') G[2].pb(x);
	}
	int r=(int)G[0].size();
	int g=(int)G[1].size();
	int b=(int)G[2].size();
	for(int i=0;i<3;i++) sort(G[i].begin(),G[i].end());
	if(odd(r)&&odd(g)&&odd(b)){
		cout<<0<<'\n';
		return 0;
	}
	if(odd(r)){
		if(r) cout<<min(Gao(G[1],G[2]),Gao2(G[0],G[1],G[2]))<<endl;
		else cout<<Gao(G[1],G[2])<<endl;
		return 0;
	}
	if(odd(g)){
		if(g) cout<<min(Gao(G[0],G[2]),Gao2(G[1],G[0],G[2]))<<endl;
		else cout<<Gao(G[0],G[2])<<endl;
		return 0;
	}
	if(odd(b)){
		if(b) cout<<min(Gao(G[0],G[1]),Gao2(G[2],G[0],G[1]))<<endl;
		else cout<<Gao(G[0],G[1])<<endl;
		return 0;
	}
	return 0;
}