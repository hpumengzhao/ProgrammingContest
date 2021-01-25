/*
* @author:  codancer
* @createTime:  2020-05-02, 20:19:15
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
	ll n,a,b;
	cin>>a>>b>>n;
	ll x=min(b-1,n);
	cout<<(x*a)/b+a*(x/b)<<endl;
	return 0;
}