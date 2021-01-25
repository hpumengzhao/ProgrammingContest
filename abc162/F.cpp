/*
* @author:  codancer
* @createTime:  2020-04-13, 10:42:14
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
const int N = 2e5+100;
ll dp[N][3];
ll a[N];
int main(){
	int n;
	cin>>n;
	rep(i,1,n){
		cin>>a[i];
	}
	rep(i,1,n){
		rep(j,0,2){
			dp[i][j]=-1e18;
		}
	}
	rep(i,1,3) dp[i][i-1]=a[i];
	rep(i,3,n){
		if(i>2){
			dp[i][0]=max(dp[i][0],dp[i-2][0])+a[i];
			dp[i][1]=max(dp[i][1],dp[i-2][1]+a[i]);
			dp[i][2]=max(dp[i][2],dp[i-2][2]+a[i]);
		}
		if(i>3){
			dp[i][1]=max(dp[i][1],dp[i-3][0]+a[i]);
			dp[i][2]=max(dp[i][2],dp[i-3][1]+a[i]);
		}
		if(i>4){
			dp[i][2]=max(dp[i][2],dp[i-4][0]+a[i]);
		}
	}
	ll ans=-1e18;
	if(n&1){
		ans=max(ans,dp[n][2]);
		if(n>1){
			ans=max(ans,dp[n-1][1]);
		}
		if(n>2){
			ans=max(ans,dp[n-2][0]);
		}
	}else{
		ans=max(ans,dp[n][1]);
		if(n>1) ans=max(ans,dp[n-1][0]);
	}
	cout<<ans<<endl;
	return 0;
}
