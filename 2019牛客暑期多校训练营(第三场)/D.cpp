#include<bits/stdc++.h>
  
using namespace std;
long long qpow(long long a,long long b,long long mod){
    long long ans=1;
    while(b){
        if(b&1) ans=(ans%mod*a%mod)%mod;
        a=(a%mod*a%mod)%mod;
        b>>=1;
    }
    return ans%mod;
}
long long qp(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1) ans=(ans*a);
        a=(a*a);
        b>>=1;
    }
    return ans;
}
int main(){
    int T;
    //freopen("1.in","r",stdin);
    scanf("%d",&T);
    while(T--){
        long long ans=0;
        long long p,n,m;
        vector<long long> pr;
        long long re;
        scanf("%lld %lld %lld",&p,&n,&m);
        if(p==2||p==5){
            puts("0");
            continue;
        }
        if(p==3){
            cout<<n/3*m<<endl;
            continue;
        }
        vector<long long> all;
        for(int i=2;i*i<=p-1;i++){
            if((p-1)%i==0){
                if(i*i==p-1) all.push_back(i);
                else{
                    all.push_back(i);
                    all.push_back((p-1)/i);
                }
            }
        }
        all.push_back(p-1);
        long long id;//循环节
        sort(all.begin(),all.end());
        for(auto v:all){//找到循环节
            if((qpow(10,v,p))%p==1){
                id=v;break;
            }
        }
        vector<long long> nums;
        for(int i=2;i*i<=id;i++){//质因子分解
            if(id%i==0){
                 int num=0;
                pr.push_back(i);
                while(id%i==0){
                     id/=i;
                     num++;
                }
                nums.push_back(num);
            } 
        }
        if(id!=1){
             pr.push_back(id);
             nums.push_back(1);
        }
        long long g;
        for(long long j=1;j<=min((long long)m,(long long)30);j++){
            g=1;
            for(int i=0;i<(int)nums.size();i++){
                g*=qp(pr[i],(nums[i]+j-1)/j);
            }
            if(j==30) ans+=(n/g)*(m-29);
            else ans+=n/g;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
