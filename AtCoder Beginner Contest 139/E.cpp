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
queue<int> G[N];
int maxx[N];
bool vis[N];
ll a[2000][2000];
int main(){
   //freopen("1.in", "r", stdin);
    ll n;
    read(n);
    rep(i,1,n){
        maxx[i]=0;
        rep(j,1,n-1){
            read(a[i][j]);
            G[i].push(a[i][j]);
        }
    }
    int ans=0;
    while(1){
        bool flag=0;
        rep(i,1,n){
            if(G[i].empty()) continue;
            if(G[G[i].front()].front()==i){
                maxx[i]=maxx[G[i].front()]=max(maxx[i],maxx[G[i].front()])+1;
                G[G[i].front()].pop();
                G[i].pop();
                flag=1;
            }
        }
        if(flag==0){
            cout<<-1<<endl;
            return 0;
        }
        ll num=0;
        rep(i,1,n){
            num+=G[i].size();
        }
        if(num==0){
            break;
        }
    }
    rep(i,1,n){
        ans=max(ans,maxx[i]);
    }
    cout<<ans<<endl;
    return 0;
}
