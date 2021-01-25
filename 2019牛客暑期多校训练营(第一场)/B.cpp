#include<bits/stdc++.h>
 
using namespace std;
const int mod = 1e9+7;
const int N = 10000;
long long qpow(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1) ans=(ans%mod*a%mod)%mod;
        a=(a%mod*a%mod)%mod;
        b>>=1;
    }
    return ans;
}
long long invs[N],a[N];
int main(){
    long long n;
    while(cin>>n){
        for(int i=1;i<=n;i++) cin>>a[i];
        long long ans=0;
        for(int i=1;i<=n;i++){
            long long temp=a[i];
            for(int j=1;j<=n;j++){
                if(i!=j){
                    temp=(temp%mod*(a[i]%mod*a[i]%mod-a[j]%mod*a[j]%mod%mod))%mod;
                    temp%=mod;
                }
            }
            invs[i]=qpow(temp,mod-2);
        }
        ans=invs[1];
        for(int i=2;i<=n;i++){
            ans+=invs[i];
            ans+=mod;
            ans%=mod;
        }
        if(n%2==0) cout<<(ans%mod*qpow(mod-2,mod-2))%mod<<endl;
        else cout<<(ans%mod*qpow(2,mod-2))%mod<<endl;
    }
    return 0;
}
