/*
* @author:  codancer
* @createTime:  2020-04-05, 16:05:46
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 998244353;
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define fep(i,a,b) for(int i=(a);i>=(b);i--)
typedef vector<int> VI;
typedef vector<ll> VII;
typedef pair<int,int> pii;
const int N = 100000+10;
ll lowbit(ll x){
	return x&(-x);
}
int main(){
	ll n;
	cin>>n;
	ll ans=0;
	rep(i,1,n){
		for(ll j=1;j*j<=i;j++){
			if(i%j==0){
				if(j*j==i){
					ans+=lowbit(j);
				}else{
					ans+=lowbit(j);
					ans+=lowbit(i/j);
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

