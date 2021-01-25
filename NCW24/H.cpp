/*
* @author:  codancer
* @createTime:  2020-04-18, 19:46:19
*/
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
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
inline char nc() {
	static char buf [100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read() {
	static char c=nc(); int x=0,f=1;
	for(;c>'9'||c<'0';c=nc()) if(c=='-') f=-1;
	for(;c<='9'&&c>='0';c=nc()) x=(x<<3)+(x<<1)+c-48;
	return x*f;
}
struct DSU{
    gp_hash_table<int,int> par;
    unordered_set<int> all;
    inline void init(){
        for(int v:all){
            par[v]=v;
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
        par[x]=y;
    }
};
void solve(){
    int n,a,b,c;
    n=read();
    goods.clear();
    bads.clear();
    DSU fr;
    rep(i,1,n){
    	a=read();
    	b=read();
    	c=read();
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