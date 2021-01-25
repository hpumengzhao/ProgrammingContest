#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=500+10;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[maxn][maxn];
int mx[maxn];
int mi[maxn];
int main()
{
    int t;
    int n,m;
    t=read();
    int x=0;
    while(t--){
        x++;
        n=read();m=read();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                a[i][j]=read();
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int i=1;i<=n;i++){
                mx[i]=0;mi[i]=INF;
            }
            for(int j=i;j<=n;j++){
                deque<int>que1,que2;
                int l=1;
                for(int k=1;k<=n;k++){
                    mx[k]=max(mx[k],a[j][k]);
                    mi[k]=min(mi[k],a[j][k]);
                    while(!que1.empty() && mx[que1.back()]<mx[k]) que1.pop_back();que1.push_back(k);
                    while(!que2.empty() && mi[que2.back()]>mi[k]) que2.pop_back();que2.push_back(k);
                    while(!que1.empty() && !que2.empty() && mx[que1.front()]-mi[que2.front()]>m){
                        if(que1.front()==que2.front()) que1.pop_front(),que2.pop_front();
                        else if(que1.front()<que2.front()) l=que1.front()+1,que1.pop_front();
                        else l=que2.front()+1,que2.pop_front();
                    }
                    if(que1.empty() || que2.empty()){
                        l=k+1;
                         continue;
                    }
                    l=min(l,min(que1.front(),que2.front()));
                    ans=max(ans,(j-i+1)*(k-l+1));
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
