#include<bits/stdc++.h>

using namespace std;
const int N = 1e6+100;
typedef long long ll;
ll a[N],b[N];
int main(){
    int T;scanf("%d",&T);
    int cas=1;
    while(T--){
        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        a[n+1]=0;
        for(int i=1;i<=n+1;i++){
            b[i]=a[i]-a[i-1];
        }
        ll check=0;
        int l,r;
        bool flag=0;
        for(l=1,r=4;l<=n;l++,r++){
            if(b[l]>0)check+=b[l];
            if(r<=n+1&&b[r]<0) check+=b[r];
            if(check<0){
                flag=1;break;
            }
        }
        printf("Case #%d: ",cas++);
        if(flag||check){
            puts("No");
        }else{
            puts("Yes");
        }
    }
    return 0;
}
