/*
* @author:  codancer
* @createTime:  2020-03-27, 19:56:05
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
ll dp[1002][1002];
int pre[2000],last[2000];
char s[2000];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	rep(i,1,n){
		int c=s[i]-'a';
		pre[i]=last[c];
		last[c]=i;
	}
	rep(i,0,n) dp[i][0]=1;
	rep(i,1,n){
		rep(j,1,i){
			dp[i][j]=(dp[i-1][j]%mod+dp[i-1][j-1]%mod)%mod;
			if(pre[i]){
				dp[i][j]-=dp[pre[i]-1][j-1]%mod;
				dp[i][j]+=mod;
				dp[i][j]%=mod;
			}
		}
	}
	ll ans=0;
	cout<<dp[n][k]<<endl;
	return 0;
}