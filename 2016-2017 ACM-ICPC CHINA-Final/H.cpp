#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll qpow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans%mod;
}
int main(){
    int T;scanf("%d",&T);
    int cas=1;
    while(T--){
        ll n,m,k;
        scanf("%lld %lld %lld",&n,&m,&k);
        long long ans=0;
        for(int kk=0;kk<=k-1;kk++){
            ans+=(qpow(kk,n+m-2)%mod*qpow(k,n*m-(n+m-1))%mod);
            ans%=mod;
        }
        ans*=n;
        ans%=mod;
        ans*=m;
        ans%=mod;
        ans+=qpow(k,n*m);
        ans%=mod;
        printf("Case #%d: %lld\n",cas++,ans);
    }
    return 0;
}
