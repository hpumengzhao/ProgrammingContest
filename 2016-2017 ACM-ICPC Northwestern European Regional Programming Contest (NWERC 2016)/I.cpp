#include<bits/stdc++.h>

using namespace std;
const int N  = 4e5+100;
typedef long long ll;
vector<pair<int,int> > G[N],G1[N],G2[N];
struct node{
    int id;
    int dis;
};
bool operator<(node a,node b){
    return a.dis>b.dis;
}
bool vis[N];
int d[N],d1[N],dc[N],di[N];
priority_queue<node> q;
void dij(int s){
    memset(vis,0,sizeof(vis));
    while(!q.empty()) q.pop();
    memset(d,0x3f,sizeof(d));
    d[s]=0;
    q.push({s,0});
    while(!q.empty()){
        node rt=q.top();q.pop();
        int u=rt.id;
        if(vis[u]) continue;
        vis[u]=1;
        for(auto V:G[u]){
            int v=V.first;
            int w=V.second;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                q.push({v,d[v]});
            }
        }
    }
}
vector<int> coal,iron;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,c,o,x;
    cin>>n>>c>>o;
    for(int i=1;i<=c;i++){
        cin>>x;
        coal.push_back(x);
    }
    for(int i=1;i<=o;i++){
        cin>>x;
        iron.push_back(x);
    }
    for(int i=1;i<=n;i++){
        int num;
        cin>>num;
        for(int j=1;j<=num;j++){
            cin>>x;
            G[i].push_back({x,1});
            G1[x].push_back({i,1});//反边
        }
    }
    dij(1);
    for(int i=1;i<=n;i++) d1[i]=d[i];
    for(int i=1;i<=n;i++){
         G[i].clear();
         G[i]=G1[i];
    }
    for(int v:iron) G[0].push_back({v,0});
    dij(0);
    for(int i=1;i<=n;i++) di[i]=d[i];
    G[0].clear();
    for(int v:coal) G[0].push_back({v,0});
    dij(0);
    for(int i=1;i<=n;i++) dc[i]=d[i];
    ll ans=1000000;
    for(int i=1;i<=n;i++) ans=min(ans,(ll)d1[i]+dc[i]+di[i]);
    if(ans==1000000) cout<<"impossible"<<endl;
    else cout<<ans<<endl;
    return 0;
}
