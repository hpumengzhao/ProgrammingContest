/*
* @author:  codancer
* @createTime:  2020-03-28, 20:32:11
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define fep(i,a,b) for(ll i=(a);i>=(b);i--)
typedef vector<int> VI;
typedef vector<ll> VII;
typedef pair<int,int> pii;
const int N = 2e5+100;
ll dis[N];
int main(){
	ll n,x,y;
	cin>>n>>x>>y;
	rep(i,1,n){
		rep(j,i,n){
			ll d=min(j-i,abs(i-x)+1+abs(j-y));
			++dis[d];
		}
	}
	rep(i,1,n-1){
		cout<<dis[i]<<endl;
	}
	return 0;
}