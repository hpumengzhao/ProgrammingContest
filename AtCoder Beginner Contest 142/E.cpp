#include<bits/stdc++.h>
 
using namespace std;
long long dp[1<<15];
const int N = 1e6+100;
long long a[N],b[N],c[N];
int main(){
    int n,m,x;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i]>>b[i];
        c[i]=0;
        for(int j=1;j<=b[i];j++){
            cin>>x;
            c[i]+=(1<<(x-1));
        }
    }
    long long s=(1<<(n))-1;
    //cout<<s<<endl;
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int i=0;i<=s;i++){
        for(int j=1;j<=m;j++){
            dp[i|c[j]]=min(dp[i|c[j]],dp[i]+a[j]);
        }
    }
    if(dp[s]==4557430888798830399LL) puts("-1");
    else cout<<dp[s]<<endl;
    return 0;
}
