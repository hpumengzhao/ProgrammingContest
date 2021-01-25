#include<bits/stdc++.h>
 
using namespace std;
bool check(long long n){
    if(n==1) return 0;
    if(n==2) return 1;
    for(long long i=2;i*i<=n;i++){
        if(n%i==0) return 0;
    }
    return 1;
}
int main(){
    long long a,b;
    cin>>a>>b;
    long long c=__gcd(a,b);
    vector<long long> prs;
    for(long long i=2;i*i<=c;i++){
        if(c%i==0){
            if(i*i==c) prs.push_back(i);
            else{
                prs.push_back(i);
                prs.push_back(c/i);
            }
        }
    }
    long long ans=1;
    for(long long v:prs){
        if(check(v)) ans++;
    }
    if(check(c)) ans++;
    cout<<ans<<endl;
    return 0;
}
