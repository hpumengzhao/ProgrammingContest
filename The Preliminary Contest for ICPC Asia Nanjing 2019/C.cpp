#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+100;
const int mod = 1e9+7;
typedef long long ll;
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
int T,n,m,u,v;
double day[N],cost[N],d[N];
bool vis[N];
vector<int> G[N];
double dfsa(int u){
    if(day[u]) return day[u];
    if(u==n) return day[u];
    double x=0;
    for(int v:G[u]){
        dfsa(v);
        x+=(day[v]+1)/(d[u]+1);
    }
    x+=1.0/(d[u]+1);
    return day[u]=x*(d[u]+1)/(d[u]);
}
double dfsb(int u){
    if(cost[u]) return cost[u];
    if(u==n) return cost[u];
    double y=0;
    for(int v:G[u]){
        dfsb(v);
        y+=(cost[v]+day[v]+1)/(d[u]+1);
    }
    y+=(day[u]+1)/(d[u]+1);
    return cost[u]=(y*(d[u]+1))/(d[u]);
}
int main(){
    //freopen("1.in", "r", stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&m);
        rep(i,1,n){
            d[i]=0,G[i].clear();
            day[i]=cost[i]=0;
        }
        rep(i,1,m){
            scanf("%d %d",&u,&v);
            G[u].push_back(v);
            d[u]+=1.0;
        }
        dfsa(1);
        printf("%.2lf\n",dfsb(1));
    }
    return 0;
}
