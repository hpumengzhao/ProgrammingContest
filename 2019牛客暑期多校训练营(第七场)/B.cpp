#include<bits/stdc++.h>
 
using namespace std;
const int N = 3000;
long long a[N];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;scanf("%d",&n);
        for(int i=1;i<=n+1;i++) scanf("%lld",&a[i]);
        if(n>=3){
            puts("No");continue;
        }
        if(n<=1){
            puts("Yes");continue;
        }
        if(a[2]*a[2]-4*a[1]*a[3]>=0){
            puts("No");
        }
        else puts("Yes");
    }
    return 0;
}
