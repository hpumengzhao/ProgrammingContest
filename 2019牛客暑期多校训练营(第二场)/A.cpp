#include<bits/stdc++.h>
 
using namespace std;
const int mod = 1e9+7;
long long qp(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1) ans=(ans%mod*a%mod)%mod;
        a=(a%mod*a%mod)%mod;
        b>>=1;
    }
    return ans%mod;
}
int main(){
    int T;
    scanf("%d",&T);
    long long ans=1;
    while(T--){
        long long n,m;
        scanf("%lld %lld",&n,&m);
        if(n==1){
            ans*=1;
        }
        else{
            if(m==0){
                ans=0;
            }
            else{
                ans*=qp(n-1,mod-2);
                ans%=(mod);
            }  
        }
        cout<<ans<<endl;
    }
    return 0;
}
