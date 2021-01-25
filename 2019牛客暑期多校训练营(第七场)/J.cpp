#include<bits/stdc++.h>
 
using namespace std;
long long f(long long x){
    long long ans=0;
    while(x){
        ans=ans*10+x%10;
        x/=10;
    }
    return ans;
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
        long long A,B;
        scanf("%lld %lld",&A,&B);
        printf("%lld\n",f(f(A)+f(B)));
    }
    return 0;
}
