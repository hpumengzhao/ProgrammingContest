/*
* @author:  codancer
* @createTime:  2020-04-14, 19:12:10
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
ll dp[3700][3700];
void solve(){
	int n;
	scanf("%d",&n);
	vector<int> a(n+1);
	rep(i,1,n){
		scanf("%d",&a[i]);
	}
	if(n>3600){
		puts("YES");
		return ;
	}
	memset(dp,0,sizeof(dp));
	rep(i,1,n){
		dp[i][a[i]%3600]=1;
		rep(j,0,3600){
			if(dp[i-1][j]){
				dp[i][j]=1;//不选
				dp[i][(a[i]+j)%3600]=1;
			}
		}
	}
	rep(i,1,n){
		if(dp[i][0]){
			puts("YES");
			return ;
		}
	}
	puts("NO");
}
int main(){
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}