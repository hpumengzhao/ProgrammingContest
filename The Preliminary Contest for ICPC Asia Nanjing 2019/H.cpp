#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
typedef long long ll;
const int N = 401;
const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f3f;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define fep(i,a,b) for(int i=(a);i>=(b);i--)
inline bool read(ll &num) {
    char in;bool IsN=false;
    in=getchar();
    if(in==EOF) return false;
    while(in!='-'&&(in<'0'||in>'9')) in=getchar();
    if(in=='-'){ IsN=true;num=0;}
    else num=in-'0';
    while(in=getchar(),in>='0'&&in<='9'){
            num*=10,num+=in-'0';
    } 
    if(IsN) num=-num;
    return true;
}
ll dis[N];
int s,t,n,m,u,v;
ll w;
vector<pair<int,ll> > G[N];
bool vis[N];
void SPFA(int s)//若存在负环返回false
{
    queue<int> q;
    memset(vis,0,sizeof(vis));
    rep(i,0,n) dis[i]=llINF;
    dis[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        vis[u]=0;
        for(auto V:G[u]){
            int v=V.first;ll w=V.second;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(!vis[v]){
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
    }
    return ;
}
int main(){
   //freopen("1.in", "r", stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        rep(i,0,n) G[i].clear();
        scanf("%d %d",&n,&m);
        rep(i,1,m){
            scanf("%d %d %lld",&u,&v,&w);
            G[u].push_back({v,w});
        }
        rep(i,1,6){
            scanf("%d %d",&s,&t);
            SPFA(t);
            printf("%lld\n",-dis[s]);
            G[s].push_back({t,-dis[s]});
        }
    }
    return 0;
}
