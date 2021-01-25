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
int main(){
	int n;
	cin>>n;
	vector<ll> a(n+1);
	rep(i,1,n) cin>>a[i];
	ll cnt[100]={0};
	rep(i,1,n){
		fep(j,63,0){
			if((a[i]>>j)&1) ++cnt[j];
		}
	}
	ll ans=0;
	fep(j,63,0){
		// if(cnt[j]) cout<<j<<' '<<cnt[j]<<endl;
		ans+=(cnt[j]*(cnt[j]))*(1LL<<j);
	}
	cout<<ans<<endl;
	return 0;
}