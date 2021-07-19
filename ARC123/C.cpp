/*
* @author:  codancer
* @createTime:  2021-07-18, 21:18:34
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
#define SZ(x) ((ll)(x).size())
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define fep(i,a,b) for(ll i=(a);i>=(b);i--)
#define deb(x) cerr<<#x<<" = "<<(x)<<"\n"
typedef vector<ll> VI;
typedef vector<ll> VII;
typedef pair<ll,ll> pii;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll Rand(ll B) {
	return (ull)rng() % B;
}
ll Gao(ll n){
	VI dig;
	while(n){
		dig.pb(n%10);
		n/=10;
	}
	bool has_zero=0;
	reverse(dig.begin(),dig.end());
	for(ll v:dig){
		if(v==0){
			has_zero=1;
			break;
		}
	}
	ll res=0;
	bool flag=0;
	ll siz=(ll)dig.size();
	if(has_zero==0){
		for(ll i=0;i<siz;i++){
			if(dig[i]>3){
				flag=1;
			}
			if(flag){
				res=res*10+3;
			}else{
				res=res*10+dig[i];
			}
		}
	}else{
		ll fid=-1;
		for(ll i=0;i<siz;i++){
			if(dig[i]==0){
				fid=i;break;
			}
		}	
		ll fe=-1;
		for(ll i=0;i<siz;i++){
			if(dig[i]>3&&i<fid){
				fe=i;
				break;
			}
		}
		if(fe!=-1){
			ll res=0;
			for(ll i=0;i<fe;i++){
				res=res*10+dig[i];
			}
			for(ll i=fe;i<siz;i++){
				res=res*10+3;
			}
			return res;
		}
		if(dig[0]>3){
			for(ll v:dig) res=res*10+3;
			return res;
		}
		if(dig[fid-1]>1){
			for(ll i=0;i<=fid-2;i++) res=res*10+min(dig[i],3LL);
			res=res*10+min(3LL,dig[fid-1]-1);
			for(ll i=fid;i<siz;i++) res=res*10+3;
			return res;
		}
		ll lst=fid-1;
		while(lst>=0&&dig[lst]==1){
			--lst;
		}
		if(lst==-1){
			for(ll i=0;i<siz-1;i++){
				res=res*10+3;
			}
			return res;
		}
		for(ll i=0;i<lst;i++){
			res=res*10+min(dig[i],3LL);
		}
		res=res*10+min(dig[lst]-1,3LL);
		for(ll i=lst+1;i<siz;i++){
			res=res*10+3;
		}
		return res;
	}
	return res;
}
void solve(){
	ll n;
	cin>>n;
	ll ans=0;
	while(n){
		if(n==0){
			break;
		}
		n-=Gao(n);
		++ans;
	}
	cout<<ans<<endl;
}
int main(){

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}