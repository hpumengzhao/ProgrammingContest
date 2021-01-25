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
unordered_map<int,int> par;
int find(int x){
    if(par[x]==0){
        par[x]=x;
        return x;
    }
    return x==par[x]?x:par[x]=find(par[x]);
}
int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    int op,x;
    while(q--){
        scanf("%d %d",&op,&x);
        if(op==1){
            par[find(x)]=x+1;
        }else{
            if(find(x)>n) puts("-1");
            else printf("%d\n",find(x));
        }
    }
    return 0;
}
