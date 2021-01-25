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
const int N = 200;
long long dp[60][40][2000];//dp[i][j][k]表示第i行拿j个总共k个的最大值
long long a[N][N];
long long pre[N][N];
int main(){
	int T;
	cin>>T;
	int cas=1;
	while(T--){
		int n,k,p;
		cin>>n>>k>>p;
		rep(i,1,n){
			pre[i][0]=0;
			rep(j,1,k){
				cin>>a[i][j];
				pre[i][j]=pre[i][j-1]+a[i][j];
			}
		}
		memset(dp,0,sizeof(dp));
		rep(i,1,n){//第i行
			rep(j,0,k){
				rep(u,0,k){
					rep(last,0,p){
						dp[i][j][last+j]=max(dp[i-1][u][last]+pre[i][j],dp[i][j][last+j]);
					}
				}
			}
		}
		ll ans=0;
		rep(i,1,n){
			rep(j,0,k){
				ans=max(ans,dp[i][j][p]);
			}
		}
		printf("Case #%d: %lld\n",cas++,ans);
	}
	return 0;
}