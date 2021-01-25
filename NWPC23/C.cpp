/*
* @author:  codancer
* @createTime:  time
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define fep(i,a,b) for(int i=(a);i>=(b);i--)
typedef vector<int> VI;
typedef vector<ll> VII;
typedef pair<int,int> pii;
ll n,m;
bool bigger(__int128 k){
	__int128 n1=n;
	__int128 m1=m;
	return k*n1-(k+1)*k/2>m;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m;
		__int128 l=0;
		__int128 r=1e18;
		for(int i=1;i<=200;i++){
			__int128 mid=(l+r)/2;
			if(bigger(mid))
		}
	}
	return 0;
}