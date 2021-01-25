#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+100;
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
int mxx[N],a[N];
int n,m;
void pushup(int rt){
    mxx[rt]=max(mxx[rt<<1],mxx[rt<<1|1]);
}
void buildtree(int rt,int l,int r){
    mxx[rt]=0;
    if(l==r){
        mxx[rt]=a[l];return ;
    }
    int mid=(l+r)>>1;
    buildtree(rt<<1,l,mid);
    buildtree(rt<<1|1,mid+1,r);
    pushup(rt);
}
int query(int rt,int l,int r,int x){
   // cout<<rt<<' '<<l<<' '<<r<<' '<<mxx[rt]<<endl;
    if(l==r){
        if(mxx[rt]>=x){
             return l;
        }
        else return -1;
    }
    int mid=(l+r)>>1;
    if(mxx[rt<<1|1]>=x){
        return query(rt<<1|1,mid+1,r,x);//先查
    }else{
        return query(rt<<1,l,mid,x);
    }
}
int main(){
    //freopen("1.in", "r", stdin);
    scanf("%d %d",&n,&m);
    rep(i,1,n) scanf("%d",&a[i]);
    buildtree(1,1,n);
    vector<int> ans;
    rep(i,1,n){
        int id=query(1,1,n,a[i]+m);
        if(id<=i) ans.push_back(-1);
        else{
            ans.push_back(id-i-1);
        }
    }
    printf("%d",ans[0]);
    rep(i,1,(int)ans.size()-1) printf(" %d",ans[i]);
    puts("");
    return 0;
}
