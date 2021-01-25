#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
const ll maxn=1000000+10;
const ll mod=1000000000+7;
ll qp(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
template<typename T>
inline ll pow(ll x,T y)
{
    ll res=1;
    x%=mod;
    for(;y;y>>=1,x=(ll)x*x%mod)if(y&1)res=(ll)res*x%mod;
    return res;
}
inline ll Quadratic_residue(const ll a)
{
    if(a==0)return 0;
    ll b=(rand()<<14^rand())%mod;
    while(pow(b,(mod-1)>>1)!=mod-1)b=(rand()<<14^rand())%mod;
    ll s=mod-1,t=0,x,inv=pow(a,mod-2),f=1;
    while(!(s&1))s>>=1,t++,f<<=1;
    t--,x=pow(a,(s+1)>>1),f>>=1;
    while(t){
        f>>=1;
        if(pow((inv*x%mod*x%mod),f)!=1)x=x*pow(b,s)%mod;
        t--,s<<=1;
    }
    return min(x,mod-x);
}
bool check(ll a,ll b,ll c){
    if((a+b)&1) b+=mod;
    if(b<a) return false;
    ll x=(a+b)/2,y=(b-a)/2;
    if(b>=mod) b-=mod;
    if(x>y) swap(x,y);
    if((x+y)%mod==b && x*y%mod==c && x<mod && y<mod){
        printf("%lld %lld\n",x,y);
        return true;
    }
    return false;
}
int main()
{
    ll t,b,c;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld %lld",&b,&c);
        ll x=((b*b-4*c)%mod+mod)%mod;
        if(qp(x,(mod-1)/2)==-1) printf("-1 -1\n");
        else{
            ll a=Quadratic_residue(x);
            if(check(a,b,c)) continue;
            else if(check(mod-a,b,c)) continue;
            else printf("-1 -1\n");
        }
    }
    return 0;
}
