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
ll qpow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) ans=(ans%mod*a%mod)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ans%mod;
}
ll inv(ll a){
    return qpow(a,mod-2);
}
vector<int> G[N];
int depth[N],maxxh[N],siz[N];
void dfs(int u,int par){
    depth[u]=depth[par]+1;
    maxxh[u]=depth[u];
    for(int v:G[u]){
        if(v==par) continue;
        siz[u]++;
        dfs(v,u);
        maxxh[u]=max(maxxh[u],maxxh[v]);
    }
}
ll dp[N];
ll solve(ll u,ll fa){
    if(siz[u]==0) return dp[u]=1;
    ll ans=0;
    for(int v:G[u]){
        if(v==fa) continue;
        if(maxxh[v]==maxxh[1]){
            ans+=solve(v,u);
        }
    }
    ans=ans*inv(siz[u])%mod;
    return dp[u]=(1-qpow(1-ans+mod,siz[u])+mod)%mod;
}
int main(){
    int n,u,v;
    cin>>n;
    rep(i,1,n-1){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,1);
    cout<<solve(1,1)<<endl;
    return 0;
}
