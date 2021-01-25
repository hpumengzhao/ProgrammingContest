#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10;
vector<int>vec[maxn],mp[maxn];
int vis[maxn];
int len[maxn];
int res=0,maxx=0,p;
bool dfs(int x,int pre){
    bool flag=0;
    if(vis[x]) flag=true;
    for(int i=0;i<vec[x].size();i++){
        int y=vec[x][i];
        if(y==pre) continue;
        if(dfs(y,x)){
            flag=true;
            mp[x].push_back(y);
            mp[y].push_back(x);
//          printf("%d %d\n",x,y);
        }
    }
    return flag;
}
void dfs2(int x,int pre,int step){
//  printf("%d\n",x);
    if(vis[x]){
        if(step>maxx){
            maxx=step;
            p=x;
        }
    }
    for(int i=0;i<mp[x].size();i++){
        int y=mp[x][i];
        if(y==pre) continue;
        dfs2(y,x,step+1);
    }
}
int main()
{
    int n,k,u,v;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n-1;i++){
        scanf("%d %d",&u,&v);
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    int x;
    for(int i=0;i<k;i++){
        scanf("%d",&x);
        vis[x]=1;
    }
    vis[x]=0;
    dfs(x,0);
    dfs2(x,0,0);
    vis[x]=1;
//  printf("___________________\n");
    maxx=0;
    dfs2(p,0,0);
    printf("%d\n",(maxx+1)/2);
    return 0;
}
