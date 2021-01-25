#include<bits/stdc++.h>
using namespace std;
const int maxn=1000+10;
int a[maxn];
int n,k;
bool vis[maxn];
bool check(int x){
    memset(vis,0,sizeof(vis));
    int res=k;
    int sum=0,maxx;
    while(res){
        res--;
        maxx=x;
        for(int i=n-1;i>=0;i--){
            if(a[i]>maxx || vis[i]) continue;
            maxx-=a[i];
            vis[i]=1;
        }
    }
    for(int i=0;i<n;i++) if(!vis[i]) return false;
    if(res>0) return true;
    else if(res==0 && maxx>=0) return true;
    else return false;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int q=1;q<=t;q++){
        scanf("%d %d",&n,&k);
        int sum=0;
        int maxx=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            maxx=max(maxx,a[i]);
            sum+=a[i];
        }
        sort(a,a+n);
        int l=sum/k,r=sum/k+5000;
        //printf("%d %d\n",l,r);
        for(int i=l;i<=r;i++){
            if(check(i)){
                printf("Case #%d: %d\n",q,i);
                break;
            }
        }
    }
    return 0;
}
