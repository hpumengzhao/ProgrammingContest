#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,b[10086][10086],ans=0;
bool a[10086][10086];
int main()
{
    // freopen("stir.in","r",stdin);
    // freopen("stir.out","w",stdout);
    cin>>n>>m>>x>>y;
     memset(a,0,sizeof(a));
     a[x][y]=1;a[x-1][y-2]=1;
     a[x-2][y-1]=1;a[x+1][y-2]=1;
     a[x+2][y-1]=1;a[x-1][y+2]=1;
     a[x-2][y+1]=1;
     a[x+1][y-2]=1;a[x+2][y-1]=1;
     for(int i=0;i<=n;i++)
     {
         if(a[i][0]!=1) b[i][0]=1;
         else break;
     }
     for(int i=0;i<=m;i++)
     {
         if(a[0][i]!=1) b[0][i]=1;
         else break;
     }
     for(int i=1;i<=n;i++)
     {
         for(int j=1;j<=m;j++)
         {
             if(!a[i][j]) b[i][j]+=(b[i-1][j]+b[i][j-1]);
             else b[i][j]=0;
         }
     }
     cout<<b[n][m]<<endl;
 return 0;
}