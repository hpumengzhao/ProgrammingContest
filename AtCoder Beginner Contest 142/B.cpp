#include<bits/stdc++.h>
 
using namespace std;
int main(){
    int n,k,x;
    cin>>n>>k;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(x>=k) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
