#include<bits/stdc++.h>
 
using namespace std;
const int N = 3e6+100;
long long maxx[N*5],minn[N*5];
long long a[N],b[N],sum[N],pre[N];
map<long long,int> pos;
void pushup(int rt){
    maxx[rt]=max(maxx[rt<<1],maxx[rt<<1|1]);
    minn[rt]=min(minn[rt<<1],minn[rt<<1|1]);
}
void bt(int rt,int l,int r){
    if(l==r){
        maxx[rt]=minn[rt]=pre[l];
        return ;
    }
    int mid=(l+r)>>1;
    bt(rt<<1,l,mid);
    bt(rt<<1|1,mid+1,r);
    pushup(rt);
}
long long querymaxx(int rt,int l,int r,int nl,int nr){
    if(nl<=l&&r<=nr){
        return maxx[rt];
    }
    long long ans=0;
    int mid=(l+r)>>1;
    if(nl<=mid) ans=max(ans,querymaxx(rt<<1,l,mid,nl,nr));
    if(nr>mid) ans=max(ans,querymaxx(rt<<1|1,mid+1,r,nl,nr));
    return ans;
}
long long queryminn(int rt,int l,int r,int nl,int nr){
    if(nl<=l&&r<=nr){
        return minn[rt];
    }
    long long ans=99999999999999;
    int mid=(l+r)>>1;
    if(nl<=mid) ans=min(ans,queryminn(rt<<1,l,mid,nl,nr));
    if(nr>mid) ans=min(ans,queryminn(rt<<1|1,mid+1,r,nl,nr));
    return ans;
}
int L[N],R[N];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++) scanf("%lld",&b[i]),pre[i]=pre[i-1]+b[i];
    bt(1,1,n);
    stack<long long> sta;
    for(int i=1;i<=n;i++){
        while(sta.size()&&a[sta.top()]>=a[i]) sta.pop();
        if(sta.empty()) L[i]=1;
        else L[i]=sta.top()+1;
        sta.push(i);
    }
    while(sta.size()) sta.pop();
    for(int i=n;i>=1;i--){
        while(sta.size()&&a[sta.top()]>=a[i]) sta.pop();
        if(sta.empty()) R[i]=n;
        else R[i]=sta.top()-1;
        sta.push(i);
    }
    long long ans=-99999999999999999;
    for(int i=1;i<=n;i++){
        if(a[i]<0){
            if(i>L[i]) ans=max(ans,a[i]*(queryminn(1,1,n,i,R[i])-querymaxx(1,1,n,L[i],i-1)));
            else ans=max(ans,a[i]*(queryminn(1,1,n,i,R[i])-pre[i-1]));
            //cout<<i<<' '<<L[i]<<' '<<R[i]<<' '<<ans<<' '<<endl;
        }
        else{
            if(i>L[i]) ans=max(ans,a[i]*(querymaxx(1,1,n,i,R[i])-queryminn(1,1,n,L[i],i-1)));
            else ans=max(ans,a[i]*(querymaxx(1,1,n,i,R[i])-pre[i-1]));
        }
    }
    printf("%lld\n",ans);
    return 0;
}
