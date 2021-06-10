/*
* @author:  codancer
* @createTime:  2021-06-09, 19:43:32
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
bool prime(int x){
	if(x==1) return 0;
	if(x==2) return 1;
	for(int i=2;i*i<=x;i++){
		if(x%i==0) return 0;
	}
	return 1;
}
ll ans=0;
const int N = 1e7+10;
vector<int> prs;
bool vis[N];
void init(int n){
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			prs.pb(i);
			for(int j=2*i;j<=n;j+=i) vis[j]=1;
		}
	}
}
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1) ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}
int main(){
	int n;
	cin>>n;
	init(n);
	ll ans=0;
	rep(i,1,n){
		if(!vis[i]){
			++ans;
			continue;
		}
		int fac;
		for(int v:prs){
			if(i%v==0){
				fac=v;break;
			}
		}
		int tmp=i;
		int cnt=0;
		while(tmp%fac==0){
			tmp/=fac;
			++cnt;
		}
		if(tmp==1) ans+=qpow(fac,cnt/2);
		else{
			ans+=tmp*qpow(fac,cnt/2);
		}
	}
	cout<<ans<<endl;
	return 0;
}