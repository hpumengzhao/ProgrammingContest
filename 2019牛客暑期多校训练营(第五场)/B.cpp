#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll x0,x1,a,b,mod;
char n[1000000+10];
struct node{
    ll a[2][2];
};
node operator *(node x,node y){
    node res;
    for(ll i=0;i<2;i++){
        for(ll j=0;j<2;j++){
            res.a[i][j]=0;
            for(ll k=0;k<2;k++){
                res.a[i][j]=(res.a[i][j]+x.a[i][k]*y.a[k][j])%mod;
            }
        }
    }
    return res;
}
node qp(node a,ll b){
    node res;
    res.a[0][0]=res.a[1][1]=1;
    res.a[0][1]=res.a[1][0]=0;
    while(b){
        if(b&1) res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}
int main()
{
    scanf("%lld %lld %lld %lld %s %lld",&x0,&x1,&a,&b,&n,&mod);
    node res;
    res.a[0][0]=a;res.a[0][1]=b;
    res.a[1][0]=1;res.a[1][1]=0;
    node ans;
    ans.a[0][0]=ans.a[1][1]=1;
    ans.a[1][0]=ans.a[0][1]=0;
    ll len=strlen(n);
    for(ll i=len-1;i>=0;i--){
        if(n[i]!='0'){
            n[i]--;
            for(ll j=i+1;j<len;j++) n[j]='9';
            break;
        }
    }
    // printf("%s\n",n);
    for(ll i=len-1;i>=0;i--){
        ll q=n[i]-'0';
        for(ll i=0;i<q;i++){
            ans=ans*res;
        }
        res=qp(res,10);
    }
    printf("%lld\n",(ans.a[0][0]*x1+ans.a[0][1]*x0)%mod);
    return 0;
}
