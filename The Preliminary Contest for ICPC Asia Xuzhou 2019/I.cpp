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

int n,m;
int c[N];
int lowbit(ll x){
    return (x&(-x));
}
void add(ll x,ll v){
    for(;x<N;x+=lowbit(x)){
         c[x]+=v;
         //cout<<x<<' '<<v<<endl;
    }
}
ll query(ll x){
    ll ans=0;
    for(;x;x-=lowbit(x)){
        ans+=c[x];
    }
    return ans;
}

int pos[N],a[N];
int l[N],r[N];
struct point{
    int x,y,flag;
}s[N];
bool cmp(point a,point b){
    if(a.x==b.x){
        if(a.y==b.y){
           return a.flag<b.flag;
        }
        return a.y<b.y;
    }
    return a.x<b.x;
}
int yy[N],id[N];
map<pair<int,int>,int> mmp;

int main(){
    scanf("%d %d",&n,&m);
    rep(i,1,n){
         scanf("%d",&a[i]);
         pos[a[i]]=i;
    }
    int cnt=0;
    rep(i,1,n){
        for(int j=2*i;j<=n;j+=i){
            s[++cnt]={pos[i],pos[j],0};
        }
    }
    rep(i,1,m){
        scanf("%d %d",&l[i],&r[i]);
        s[++cnt]={r[i],r[i],1};
        s[++cnt]={l[i]-1,r[i],1};
        s[++cnt]={r[i],l[i]-1,1};
        s[++cnt]={l[i]-1,l[i]-1,1};
    }

    rep(i,1,cnt) yy[i]=s[i].y;

    sort(yy+1,yy+cnt+1);
    int siz=unique(yy+1,yy+cnt+1)-yy-1;

    sort(s+1,s+cnt+1,cmp);
    rep(i,1,cnt){
        id[i]=lower_bound(yy+1,yy+siz+1,s[i].y)-yy;
    }
    rep(i,1,cnt){
        if(s[i].flag==0){
            add(id[i],1);
        }else{
            mmp[{s[i].x,s[i].y}]=query(id[i]);
        }
    }
    rep(i,1,m){
        printf("%d\n",mmp[{r[i],r[i]}]-mmp[{l[i]-1,r[i]}]-mmp[{r[i],l[i]-1}]+mmp[{l[i]-1,l[i]-1}]);
    }
    return 0;
}
