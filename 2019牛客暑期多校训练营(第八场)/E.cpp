#include <bits/stdc++.h>
#define ls rt<<1
#define rs rt<<1|1
using namespace std;
typedef long long ll;
const int N=1e5+5;
vector<int>G[N<<3];
int n,m,ans,cnt;
int Rank[N],b[N<<1],l[N],r[N],u[N],v[N],f[N];
inline int fin(int x){return x==f[x]?x:fin(f[x]);}
inline void update(int rt,int L,int R,int l,int r,int x){
    if(l<=L&&R<=r){
        G[rt].push_back(x);
        return ;
    }
    int mid=(L+R)>>1;
    if(l<=mid)update(ls,L,mid,l,r,x);
    if(r>mid)update(rs,mid+1,R,l,r,x);
}
inline void dfs(int rt,int l,int r){
    vector<int>lastf;
    int len=G[rt].size(),mid=(l+r)>>1;
    for(int i=0;i<len;i++){
        int x=u[G[rt][i]],y=v[G[rt][i]];
        int fx=fin(x),fy=fin(y);
        // printf("%d %d\n",fx,fy);
        ///按秩合并，不能压缩路径，这样才能在dfs完这个节点把已经连好的祖先撤销掉
        if(Rank[fx]>Rank[fy])lastf.push_back(fy),f[fy]=fx;
        else{
            lastf.push_back(fx),f[fx]=fy;
            if(Rank[fx]==Rank[fy])Rank[fy]++;
        }
    }
    if(fin(1)==fin(n)){
        ans+=b[r+1]-b[l];
        // printf("%d %d %d %d %d\n",l,r,b[l],b[r+1],ans);
    }
    else if(l<r)dfs(ls,l,mid),dfs(rs,mid+1,r);
    len=lastf.size();
    for(int i=len-1;i>=0;i--)f[lastf[i]]=lastf[i];
    ///撤销祖先
    ///父亲的深度不用还，太难还了，不还复杂度影响也不会很大
    lastf.clear();
}
int main(){
    // freopen("1.in","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)f[i]=i,Rank[i]=1;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d%d",&u[i],&v[i],&l[i],&r[i]);
        b[++cnt]=l[i],b[++cnt]=r[i]+1;
    }
    ///对离散化后的区间段左闭右开建树，每个节点代表一个左闭右开的区间，不重不漏
    sort(b+1,b+1+cnt);
    cnt=unique(b+1,b+1+cnt)-b-1;
    for(int i=1;i<=m;i++)
    update(1,1,cnt-1,lower_bound(b+1,b+1+cnt,l[i])-b,lower_bound(b+1,b+1+cnt,r[i]+1)-b-1,i);
    dfs(1,1,cnt-1);printf("%d\n",ans);
    return 0;
}
