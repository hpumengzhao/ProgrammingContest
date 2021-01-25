#include<bits/stdc++.h>
 
using namespace std;
const int N = 1e6+100;
vector<int> G[N];
int pos[50];
int mps[50][20000];
int ids[50][20000];
int alpha[N];
int ind[N];//入度
string s[50];char a[50],b[50];int l[50];
int maxx[26],num[26];
vector<int> orders;//拓扑序
int main(){
    int n,m;
    cin>>n>>m;
    int tot=0;//总的点数
    bool flag=0;
    for(int i=1;i<=m*(m-1)/2;i++){
        memset(num,0,sizeof(a));
        memset(pos,0,sizeof(pos));//字母i最新的位置
        cin>>a[i]>>b[i]>>l[i];
        if(l[i]) cin>>s[i];
        for(int j=0;j<l[i];j++){
            if(!mps[s[i][j]-'a'][++pos[s[i][j]-'a']]){
                mps[s[i][j]-'a'][pos[s[i][j]-'a']]=++tot;
                num[s[i][j]-'a']++;
            }
            ids[i][j]=mps[s[i][j]-'a'][pos[s[i][j]-'a']];
            alpha[ids[i][j]]=s[i][j]-'a';
            maxx[a[i]-'a']=max(maxx[a[i]-'a'],num[a[i]-'a']);
            maxx[b[i]-'a']=max(maxx[b[i]-'a'],num[b[i]-'a']);
        }
    }
    for(int i=1;i<=m*(m-1)/2;i++){
        //cout<<a[i]<<' '<<b[i]<<endl;
        memset(num,0,sizeof(num));
        for(int j=0;j<l[i]-1;j++){
            num[s[i][j]-'a']++;
            G[ids[i][j]].push_back(ids[i][j+1]);
            ind[ids[i][j+1]]++;//入度++
        }
        num[s[i][l[i]-1]-'a']++;
        //cout<<num[a[i]-'a']<<' '<<num[b[i]-'a']<<endl;
        if(num[a[i]-'a']!=maxx[a[i]-'a']||num[b[i]-'a']!=maxx[b[i]-'a']){
            flag=1;
        }
    }
 
    if(n!=tot||flag){
        puts("-1");return 0;
    }
    queue<int> q;
    for(int i=1;i<=max(n,tot);i++){
        if(ind[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        orders.push_back(u);
        for(int v:G[u]){
            ind[v]--;
            if(ind[v]==0) q.push(v);
        }
    }
    if(orders.size()!=n){
        puts("-1");return 0;
    }
    for(int v:orders){
        cout<<char(alpha[v]+'a');
    }
    cout<<endl;
    return 0;
}
