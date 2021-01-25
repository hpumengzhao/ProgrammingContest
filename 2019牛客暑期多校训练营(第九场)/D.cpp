#include<bits/stdc++.h>
 
using namespace std;
const int N = 50;
map<long long,string > mps1,mps2;
long long w[N],w1[N],w2[N];
set<long long> A,B;
int main(){
    int n;long long s;
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        cin>>w[i];
        if(i<=n/2) w1[i]=w[i];
        else w2[i-n/2]=w[i];
    }
    int n1=n/2;int n2=n-n1;
    for(int i=0;i<(1<<n1);i++){
        long long sum=0;
        string tt="";
        for(int j=0;j<n1;j++){
            if((i>>j)&1){
                tt+='1';
                sum+=w1[j+1];
            }
            else {
                tt+='0';
            }
        }
        mps1[sum]=tt;
        A.insert(sum);
    }
    for(int i=0;i<(1<<n2);i++){
        long long sum=0;
        string tt="";
        for(int j=0;j<n2;j++){
            if((i>>j)&1){
                tt+='1';
                sum+=w2[j+1];
            }
            else {
                tt+='0';
            }
        }
        mps2[sum]=tt;
        B.insert(sum);
    }
    for(auto v:A){
        if(B.find(s-v)!=B.end()){
            cout<<mps1[v]<<mps2[s-v]<<endl;
        }
    }
    return 0;
}
