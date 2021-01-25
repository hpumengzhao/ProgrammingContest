#include<bits/stdc++.h>

using namespace std;
const int N = 1e6+100;
int L[N],R[N],ind[N];
vector<int> toporder;
vector<int> G[N];
vector<pair<int,int> > V[N];
struct node{
    int l,r;
};
bool operator<(node a,node b){
    return a.l>b.l;
}
vector<int> ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,u,v;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>L[i]>>R[i];
    }
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        G[u].push_back(v);
        ind[v]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(ind[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int now=q.front();q.pop();
        toporder.push_back(now);
        for(int v:G[now]){
            ind[v]--;
            if(ind[v]==0) q.push(v);
        }
    }
    for(int i=1;i<=n;i++){//不是DAG
        if(ind[i]>0){
            puts("-1");return 0;
        }
    }
    int siz=toporder.size();
    for(int i=0;i<siz;i++){//处理左端点
        int u=toporder[i];
        for(int v:G[u]){
            L[v]=max(L[v],L[u]+1);//v在u的右边
        }
    }
    reverse(toporder.begin(),toporder.end());
    for(int i=0;i<siz;i++){//倒着处理右端点
        int u=toporder[i];
        for(int v:G[u]){
            R[u]=min(R[u],R[v]-1);
        }
    }
    for(int i=1;i<=n;i++){
        if(R[i]<L[i]){
            puts("-1");return 0;
        }
        V[L[i]].push_back({R[i],i});
    }
    priority_queue<node> qq;
    for(int i=1;i<=n;i++){//枚举L从1到n
        for(auto j:V[i]){//把R和id存进去
            qq.push({j.first,j.second});
        }
        if(qq.empty()||qq.top().l<i){//R小的优先
            puts("-1");return 0;
        }
        ans.push_back(qq.top().r);
        qq.pop();
    }
    for(int v:ans) cout<<v<<endl;
    return 0;
}
