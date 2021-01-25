#include<bits/stdc++.h>
 
using namespace std;
int main(){
    long long x[4],y[4];
    while(cin>>x[1]>>y[1]>>x[2]>>y[2]>>x[3]>>y[3]){
        long long S=abs(x[1]*y[2]+x[2]*y[3]+x[3]*y[1]-x[1]*y[3]-x[2]*y[1]-x[3]*y[2]);
        cout<<S*11<<endl;
        //cout<<abs(12*(x[1]*y[2]+x[2]*y[3]+x[3]*y[1]-x[1]*y[3]-x[2]*y[1]-x[3]*y[2]))<<endl;
    }
    return 0;
}
