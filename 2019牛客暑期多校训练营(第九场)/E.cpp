#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1000000+10;
ll sum[maxn];
ll pre[maxn];
ll n,m,u,v;
void init(){
    for(int i=1;i<=n;i++) pre[i]=i,sum[i]=1;
}
ll find(ll x){
    if(pre[x]!=x){
        sum[pre[x]]+=sum[x];
        sum[x]=0;
        return pre[x]=find(pre[x]);
    }
    return x;
}
void join(ll x,ll y){
    x=find(x);
    y=find(y);
    if(x<y) swap(x,y);
    sum[y]+=sum[x];
    sum[x]=0;
    pre[x]=y;
}
int main()
{
    scanf("%lld %lld",&n,&m);
    init();
    ll a[4]={n,n-1,n-2,n-3};
    for(int i=2;i<=4;i++){
        for(int j=0;j<4;j++){
            if(a[j]%i==0){
                a[j]/=i;
                break;
            }
        }
    }
    ll cur2=n*(n-1)/2,cur4=a[0]*a[1]*a[2]*a[3];
    printf("%lld\n",cur4);
    for(int i=0;i<m;i++){
        scanf("%lld %lld",&u,&v);
        if(find(u)!=find(v)){
            ll a=sum[find(u)],b=sum[find(v)];
            ll x=cur2-(n-a-b)*(a+b)-a*b;
            cur4-=x*a*b; cur2-=a*b;
            join(u,v);
            // printf("a=%lld b=%lld\n",a,b);
        }
        printf("%lld\n",cur4);
        // printf("cur4=%lld cur2=%lld\n",cur4,cur2);
    }
    return 0;
}
