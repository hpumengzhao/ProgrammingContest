#include<bits/stdc++.h>
 
using namespace std;
int main(){
    long long n;
    cin>>n;
    if(n%2==0){
        cout<<0.5<<endl;
    }else{
        printf("%.10lf\n",(n+1)/2.0/n);
    }
    return 0;
}
