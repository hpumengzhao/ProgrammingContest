/*
* @author:  codancer
* @createTime:  2021-06-07, 19:14:51
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
int main(){
	string s,t;
	cin>>s>>t;
	int n=(int)s.size();
	int m=(int)t.size();
	string ans;
	for(int i=1;i<=n;i++) ans+='z';
	bool fd=0;
	for(int i=0;i+m-1<n;i++){
		string tmp=s;
		for(int j=i;j<=i+m-1;j++){
			tmp[j]=t[j-i];
		}
		bool ok=1;
		for(int j=0;j<n;j++){
			if(s[j]=='?') continue;
			if(s[j]!=tmp[j]){
				ok=0;break;
			}
		}
		if(ok){
			for(char &c:tmp){
				if(c=='?') c='a';
			}
			ans=min(ans,tmp);
			fd=1;
		}
	}
	if(fd){
		cout<<ans<<endl;
	}else{
		cout<<"UNRESTORABLE"<<endl;
	}
	return 0;
}