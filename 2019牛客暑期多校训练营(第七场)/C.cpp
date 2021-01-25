#include<bits/stdc++.h>
 
using namespace std;
const int N = 2e5+100;
struct tree{
    long long h,p,c;
}s[N];
bool cmp(tree a,tree b){
    return a.h<=b.h;
}
long long num[301];
long long pre[N];
long long sa[N];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        memset(num,0,sizeof(num));
        map<long long,long long> nh;
        for(int i=1;i<=n;i++) scanf("%lld %lld %lld",&s[i].h,&s[i].c,&s[i].p),nh[s[i].h]+=s[i].p;
        sort(s+1,s+n+1,cmp);
        for(int i=1;i<=n;i++) pre[i]=pre[i-1]+s[i].c*s[i].p;//总花费
        for(int i=n;i>=1;i--) sa[i]=sa[i+1]+s[i].p*s[i].c;//后缀
        long long ans=99999999999999999;
        for(int i=1;i<=n;i++){
            long long re=0;
            long long all=nh[s[i].h]-1;//最多需要多少个
            for(long long j=200;j>=1;j--){
                if(num[j]<all){
                    re+=num[j]*j;
                    all-=num[j];
                }
                else{
                    re+=all*j;
                    all=0;break;
                }
            }
            num[s[i].c]+=s[i].p;
            int pos=i+1;
            while(s[pos].h==s[i].h) pos++;
            ans=min(ans,pre[i-1]-re+sa[pos]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
