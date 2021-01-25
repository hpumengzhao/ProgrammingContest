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
struct point{
    double x,y;
}s[N];
bool cmp(point a,point b){
    if(atan2(a.y,a.x)!=atan2(b.y,b.x)){
        return atan2(a.y,a.x)<atan2(b.y,b.x);
    }
    return a.x<b.x;
}
int main(){
    //freopen("1.in", "r", stdin);
    ll n;
    read(n);
    rep(i,1,n){
        cin>>s[i].x>>s[i].y;
    }
    sort(s+1,s+n+1,cmp);
    rep(i,n+1,2*n) s[i]=s[i-n];
    double ans=0;
    rep(i,1,n){
        double xx=0;
        double yy=0;
        rep(j,i,i+n-1){
            xx+=s[j].x;
            yy+=s[j].y;
            ans=max(ans,xx*xx+yy*yy);
        }
    }
    printf("%.15lf\n",sqrt(ans));
    return 0;
}
