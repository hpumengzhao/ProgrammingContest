/*
* @author:  codancer
* @createTime:  2021-07-19, 12:01:58
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
#include <iomanip>
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
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	vector<ll> pos,neg;
	char c;ll p;
	rep(i,1,n){
		cin>>c>>p;
		if(c=='+'){
			pos.pb(p);
		}else{
			neg.pb(p);
		}
	}
	ll N=(ll)pos.size();
	ll M=(ll)neg.size();
	sort(pos.begin(),pos.end());
	sort(neg.begin(),neg.end(),greater<int>());
	vector<ll> res;
	for(int v:neg){
		int id=lower_bound(pos.begin(),pos.end(),v+1)-pos.begin();
		res.pb(N-id);
	}
	res.pb(N);
	double AUC=0;
	int nowL=0;
	bool ok=0;
	for(int i=0;i<(int)res.size();i++){
		if(res[i]==res[nowL]){
			ok=0;
			continue;
		}
		else{
			// cout<<i<<endl;
			AUC+=res[nowL]*(i*1LL-nowL*1LL)*1.0/(M*N);
			nowL=i;
			ok=1;
		}
	}
	if(ok==0){
		AUC+=res[nowL]*((ll)res.size()-1-nowL*1LL)*1.0/(M*N);
	}
	cout<<fixed<<setprecision(14)<<AUC<<endl;
	return 0;
}