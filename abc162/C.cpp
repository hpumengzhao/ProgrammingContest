/*
* @author:  codancer
* @createTime:  2020-04-12, 20:06:24
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
int main(){
	int k;
	cin>>k;
	ll ans=0;
	rep(i,1,k){
		rep(j,1,k){
			rep(d,1,k){
				ans+=__gcd(i,__gcd(j,d));
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}