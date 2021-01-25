#include<bits/stdc++.h>
 
using namespace std;
const int N = 1e6+100;
char s[N];
long long sum[N];
map<int,int> mp;
int main(){
    int n;
    cin>>n;
    int ans1,ans2;
    ans1=ans2=0;
    scanf("%s",s+1);
    int n1,n2;
    n1=n2=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='1') sum[i]=sum[i-1]+1,n1++;
        else sum[i]=sum[i-1]-1,n2++;
    }
    ans2=min(n1,n2);
    for(int i=1;i<=n;i++){
        if(sum[i]==0) ans1=i;
        if(!mp[sum[i]]) mp[sum[i]]=i;
        if(mp[sum[i]]) ans1=max(ans1,i-mp[sum[i]]);
    }
    cout<<ans1<<' '<<2*ans2<<endl;
    return 0;
}
