/*
* @author:  codancer
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define pb push_back
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define fep(i,a,b) for(int i=(a);i>=(b);i--)
typedef vector<int> VI;
typedef pair<int,int> pii;
const int mod = 998244353;
ll dp[3005][3005];
int main(){
	int n,s;
	cin>>n>>s;
	vector<int> a(n+1);
	rep(i,1,n){
		cin>>a[i]; 
	}
	dp[0][0]=1;
	rep(i,1,n){
		rep(j,0,3000){
			if(j>=a[i]) dp[i][j]=(dp[i-1][j]+dp[i-1][j-a[i]])%mod;
			else dp[i][j]=dp[i-1][j];
			dp[i][j]%=mod;
		}
	}
	
	rep(i,1,n){
		cout<<i<<":"<<dp[i][s]<<endl;
	}
	
	ll ans=0;
	rep(i,1,n){
		
	}
	cout<<ans<<endl;
	return 0;
}

