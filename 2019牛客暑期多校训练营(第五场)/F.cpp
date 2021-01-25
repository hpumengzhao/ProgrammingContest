#include<bits/stdc++.h>
  
using namespace std;
const int N = 10000;
int p[N],master[N];
vector<int> G[N];
bool used[N],jud[N],T[N];
bool check(int i,int j){
    return __builtin_popcount(p[i]^p[j])==1;
}
bool find(int x){
    T[x]=1;
    for(auto v:G[x]){
        if(!used[v]){
            used[v]=1;
            if(master[v]==-1||find(master[v])){
                master[v]=x;
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    memset(master,-1,sizeof(master));
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            bool jud=check(i,j);
            if(jud==1){
                if(__builtin_parity(p[i])==1){
                    G[i].push_back(j);
                }
                else{
                    G[j].push_back(i);
                }
            }
        }
    }
    memset(T,0,sizeof(T));
    int ans=0;
    for(int i=1;i<=n;i++){
        memset(used,0,sizeof(used));
        if(find(i)){
             ans++;
             jud[i]=1;
        }
    }
    printf("%d\n",n-ans);
    memset(used,0,sizeof(used));
    memset(T,0,sizeof(T));
    for(int i=1;i<=n;i++){
        if(!jud[i]) find(i);
    }
    for(int i=1;i<=n;i++){
        if(__builtin_parity(p[i])==1&&T[i]) printf("%d ",p[i]);
        if(__builtin_parity(p[i])==0&&!used[i]) printf("%d ", p[i]);
    }
    puts("");
    return 0;
}
