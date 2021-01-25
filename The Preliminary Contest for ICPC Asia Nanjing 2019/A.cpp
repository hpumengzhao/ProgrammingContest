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
ll T,n,p,m,c[N];
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
//BIT
struct point{
    ll x,y;
    int flag;
}pp[N];
bool cmp(point a,point b){
    if(a.x==b.x){
        if(a.y==b.y){
           return a.flag<b.flag;
        }
        return a.y<b.y;
    }
    return a.x<b.x;
}

ll dig(ll x){
    ll ans=0;
    while(x){
        ans+=x%10;
        x/=10;
    }
    return ans;
}
ll cal(ll x,ll y){//计算(x,y)处的值
    x=x-n/2-1;
    y=y-n/2-1;
    ll t=max(abs(x),abs(y));
    if(x>=y) return n*n-4*t*t-2*t-x-y;
    else return n*n-4*t*t+2*t+x+y;
}
map<pair<ll,ll>,ll> mmp;
ll yy[N],id[N];
ll x__1[100001],y__1[100001],x__2[100001],y__2[100001];
int main(){
   //freopen("1.in", "r", stdin);
    read(T);
    while(T--){
        mmp.clear();
        read(n);read(m);read(p);
            //cout<<cal(2,3)<<endl;
        memset(c,0,sizeof(c));
        ll x,y,x_1,y_1,x_2,y_2;
        rep(i,1,m){
            read(x);read(y);
            pp[i]={x,y,0};
        }
        int kk=m;
        rep(i,1,p){
            read(x_1);read(y_1);read(x_2);read(y_2);
            x__1[i]=x_1;y__1[i]=y_1;x__2[i]=x_2;y__2[i]=y_2;
            pp[++m]={x_1-1,y_1-1,1};
            pp[++m]={x_2,y_2,1};
            pp[++m]={x_1-1,y_2,1};
            pp[++m]={x_2,y_1-1,1};
        }
        rep(i,1,m) yy[i]=pp[i].y;
        sort(yy+1,yy+m+1);
        int siz=unique(yy+1,yy+m+1)-yy-1;
        sort(pp+1,pp+m+1,cmp);
        rep(i,1,m){
            id[i]=lower_bound(yy+1,yy+siz+1,pp[i].y)-yy;
        }
        //离散化
        rep(i,1,m){
            if(pp[i].flag==0){
                add(id[i],dig(cal(pp[i].x,pp[i].y)));
            }
            else{
                mmp[{pp[i].x,pp[i].y}]=query(id[i]);
            }
        }
        rep(i,1,p){
            printf("%lld\n",mmp[{x__2[i],y__2[i]}]-mmp[{x__1[i]-1,y__2[i]}]-mmp[{x__2[i],y__1[i]-1}]+mmp[{x__1[i]-1,y__1[i]-1}]);
        }
    }
    return 0;
}
