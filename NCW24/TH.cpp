/*
* @author:  codancer
* @createTime:  2020-04-18, 19:46:19
*/
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define fep(i,a,b) for(int i=(a);i>=(b);i--)
typedef vector<int> VI;
typedef vector<ll> VII;
typedef pair<int,int> pii;
vector<pair<int,int> > goods,bads;
inline bool scan_d(int &num) 
{
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
struct DSU{
    unordered_map<int,int> par,siz;
    unordered_set<int> all;
    inline void init(){
        for(int v:all){
            par[v]=v;
            siz[v]=1;
        }
    }
    inline int find(int x){
        return par[x]==x?x:par[x]=find(par[x]);
    }
    inline void unite(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y){
            return ;
        }
        if(siz[x]>=siz[y]){
            par[y]=x;
            if(siz[x]==siz[y]){
                ++siz[x];
            }
 
        }else{
            par[x]=y;
        }
    }
};
void solve(){
    int n,a,b,c;
    scan_d(n);
    goods.clear();
    bads.clear();
    DSU fr;
    rep(i,1,n){
        scan_d(a);
        scan_d(b);
        scan_d(c);
        fr.all.insert(a);
        fr.all.insert(b);
        if(c){
            goods.pb({a,b});
        }else{
            bads.pb({a,b});
        }
    }
    fr.init();
    for(auto v:goods){
        fr.unite(v.first,v.second);
    }
    for(auto v:bads){
        if(fr.find(v.first)==fr.find(v.second)){
            puts("NO");
            return ;
        }
    }
    puts("YES");
    return ;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}