#include<bits/stdc++.h>
 
using namespace std;
const int N = 2000;
long long c[N][N];
long long sum[N][N];//把第i个物品升级到j级需要多少花费
long long minn[N][N];//第i个物品升级到>=j之后的最少花费
long long d[N];
long long pre[N];
int main(){
    int T;
    scanf("%d",&T);
    int cas=1;
    while(T--){
        int n,m;scanf("%d %d",&n,&m);
        if(n==1)
        for(int i=0;i<=n;i++){
            d[i]=pre[i]=0;
            for(int j=0;j<=m;j++){
                sum[i][j]=minn[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                 scanf("%lld",&c[i][j]);
                 sum[i][j]=sum[i][j-1]+c[i][j];
            }
            minn[i][m]=sum[i][m];
            for(int j=m-1;j>=0;j--){
                minn[i][j]=min(sum[i][j],minn[i][j+1]);
            }
        }
        for(int i=1;i<=m;i++) scanf("%lld",&d[i]),pre[i]=pre[i-1]+d[i];
        long long ans=0;
        for(int d=0;d<=m;d++){
            long long nowsum=pre[d];
            long long nedd=0;
            bool flag=0;
            for(int i=1;i<=n;i++){
                if(minn[i][d]>=sum[i][d]){
                    nowsum-=sum[i][d];flag=1;
                }
                else{
                    nowsum-=minn[i][d];
                }
            }
            if(!flag){
                long long nowmaxx=-9999999999999999;
                int pos=0;
                for(int i=1;i<=n;i++){
                    nowmaxx=max(nowmaxx,minn[i][d]-sum[i][d]);
                }
                nowsum=nowsum+nowmaxx;
                //cout<<d<<' '<<nowsum<<endl;
            }
            ans=max(ans,nowsum);
        }
        printf("Case #%d: %lld\n",cas++,ans);
    }
    return 0;
}
