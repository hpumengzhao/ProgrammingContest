#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,p;
    scanf("%lld %lld",&n,&p);
    ll sum=0;
    ll x=p;
    while(x){
        x/=10;
        sum++;
    }
    if(sum>n) printf("T_T\n");
    else{
        printf("%lld",p);
        for(int i=0;i<n-sum;i++) printf("0");
            printf("\n");
    }
    return 0;
}
