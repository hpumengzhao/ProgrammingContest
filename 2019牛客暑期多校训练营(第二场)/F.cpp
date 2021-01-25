#include<bits/stdc++.h>
 
using namespace std;
vector<int> w;
long long a[30][30];
long long d[30];
long long ans;
int n;
void dfs(int p,long long res){
    if(w.size()==n){
        ans=max(ans,res);
        return ;
    }
    if(p>2*n) return ;
    long long now=d[p];
    for(auto v:w) now-=2*a[p][v];//仇恨度消除
    w.push_back(p);
    dfs(p+1,res+now);
    w.pop_back();
    dfs(p+1,res);
}
int main(){
    ans=0;
    cin>>n;
    for(int i=1;i<=2*n;i++){
        for(int j=1;j<=2*n;j++){
            cin>>a[i][j];
            d[i]+=a[i][j];
        }
    }
    dfs(1,0);
    cout<<ans<<endl;
    return 0;
}
