#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const int maxn=1000000+10;
const ll mod=1000000007;
const int INF=0x3f3f3f3f;
ll dp[1000*4+10][1000*4];
int main()
{
    int n,m;
    while(~scanf("%d %d",&n,&m)){
        for(int i=1;i<=(n+m)*2;i++){
            for(int j=1000-m-1;j<=1000+n+1;j++){
                dp[i][j]=0;
            }
        }
        dp[0][1000]=1;
        for(int i=1;i<=(n+m)*2;i++){
            for(int j=1000-m;j<=1000+n;j++){
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
                dp[i][j]%=mod;
            }
        }
        printf("%lld\n",dp[(n+m)*2][1000]%mod);
    }
    return 0;
}
