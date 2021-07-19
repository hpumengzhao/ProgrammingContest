/*
* @author:  codancer
* @createTime:  2021-07-18, 21:45:22
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
ll Gao(ll n){
	VI dig;
	while(n){
		dig.pb(n%10);
		n/=10;
	}
	bool has_zero=0;
	reverse(dig.begin(),dig.end());
	for(int v:dig){
		if(v==0){
			has_zero=1;
			break;
		}
	}
	ll res=0;
	bool flag=0;
	int siz=(int)dig.size();
	if(has_zero==0){
		for(int i=0;i<siz;i++){
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
		int fid=-1;
		for(int i=0;i<siz;i++){
			if(dig[i]==0){
				fid=i;break;
			}
		}	
		int fe=-1;
		for(int i=0;i<siz;i++){
			if(dig[i]>3&&i<fid){
				fe=i;
				break;
			}
		}
		if(fe!=-1){
			ll res=0;
			for(int i=0;i<fe;i++){
				res=res*10+dig[i];
			}
			for(int i=fe;i<siz;i++){
				res=res*10+3;
			}
			return res;
		}
		if(dig[0]>3){
			for(int v:dig) res=res*10+3;
			return res;
		}
		if(dig[fid-1]>1){
			for(int i=0;i<=fid-2;i++) res=res*10+min(dig[i],3);
			res=res*10+min(3,dig[fid-1]-1);
			for(int i=fid;i<siz;i++) res=res*10+3;
			return res;
		}
		int lst=fid-1;
		while(lst>=0&&dig[lst]==1){
			--lst;
		}
		if(lst==-1){
			for(int i=0;i<siz-1;i++){
				res=res*10+3;
			}
			return res;
		}
		for(int i=0;i<lst;i++){
			res=res*10+min(dig[i],3);
		}
		res=res*10+min(dig[lst]-1,3);
		for(int i=lst+1;i<siz;i++){
			res=res*10+3;
		}
		return res;
	}
	return res;
}
bool check(int x){

	while(x){
		if(x%10==0||x%10>3){
			return 0;
		}
		x/=10;
	}
	return 1;
}
int main(){
	for(int i=1;i<=100000;i++){
		for(int j=i;j>=1;j--){
			if(check(j)){
				if(j!=Gao(i)){
					cout<<i<<' '<<j<<' '<<Gao(i)<<endl;
				}
				break;
			}
		}
	}
	return 0;
}