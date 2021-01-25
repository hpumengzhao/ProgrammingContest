#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10;
struct node{
    int x,y;
    bool friend operator <(node i,node j){
        if(i.x==j.x) return i.y<j.y;
        return i.x<j.x;
    }
}a[maxn];
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d %d",&a[i].x,&a[i].y);
        }
        sort(a+1,a+n+1);
//      for(int i=1;i<=n;i++) printf("%d %d\n",a[i].x,a[i].y);
        int x=a[n/2].x;
        int y=a[n/2].y;
        printf("%d %d %d %d\n",x-1,y+10000000+1,x+1,y-10000000);
    }
    return 0;
}
