#include<bits/stdc++.h>
 
using namespace std;
long long a[100000];
int main(){
    long long n,m;
    while(cin>>n>>m){
        long long sum2=0;
        for(int i=1;i<=n;i++){
             cin>>a[i];
             sum2+=(a[i]*a[i]);
        }
        sort(a+1,a+n+1,greater<int>());
        pair<long long ,long long> now,ans;
        ans={0,1};
        long long sum1=0;
        for(int i=1;i<=n;i++){
            sum1+=a[i];
            sum2-=a[i]*a[i];
            if(i==n||(a[i+1]*i<=(sum1-m))){
                long long up=(sum1-m)*(sum1-m)+sum2*i;
                long long down=i;
                now=make_pair(up,down);
                if(now.first*ans.second>ans.first*now.second){
                    ans=now;
                }
            }
        }
        ans.second*=(m*m);
        if(ans.first==0){
            cout<<0<<endl;
        }
        else{
            long long gc=__gcd(ans.first,ans.second);
            ans.first/=gc;
            ans.second/=gc;
            if(ans.second==1){
                cout<<ans.first<<endl;
            }
            else{
                cout<<ans.first<<'/'<<ans.second<<endl;
            }
        }
    }
    return 0;
}
