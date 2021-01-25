/*
* @author:  codancer
* @createTime:  2020-04-25, 20:00:53
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
const int N = 20000;
int w[N],dp[N];
int main(){
	int n,m;
	while(scanf("%d",&n)&&n){
		rep(i,1,n) scanf("%d",&w[i]);
		scanf("%d",&m);
		sort(w+1,w+n+1);
		memset(dp,0,sizeof(dp));
		rep(i,1,n-1){
			fep(j,m,w[i]){
				dp[j]=max(dp[j],dp[j-w[i]]+w[i]);
			}
		}
		printf("%d\n", m-dp[m]-w[n]);
	}
	return 0;
}