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
ll a[200004];
int main(){
	ll k,n;
	cin>>k>>n;
	rep(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	vector<ll> dis;
	ll minn=k-(a[n]-a[1]);
	rep(i,2,n){
		minn=max(minn,a[i]-a[i-1]);
	}
	cout<<k-minn<<endl;
	return 0;
}