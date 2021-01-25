#include<bits/stdc++.h>
 
using namespace std;
const int N = 1e6+100;
int pos[N],a[N],b[N];
int LA[N],RA[N],RB[N],LB[N];
int main(){
    int n;
    while(cin>>n){
        stack<int> sta;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),pos[a[i]]=i;
        for(int i=1;i<=n;i++){
            while(sta.size()&&a[sta.top()]>=a[i]) sta.pop();
            if(sta.empty()) LA[i]=1;
            else LA[i]=sta.top()+1;
            sta.push(i);
        }
        while(sta.size()) sta.pop();
        for(int i=n;i>=1;i--){
            while(sta.size()&&a[sta.top()]>=a[i]) sta.pop();
            if(sta.empty()) RA[i]=n;
            else RA[i]=sta.top()-1;
            sta.push(i);
        }
        while(!sta.empty()) sta.pop();
        for(int i=1;i<=n;i++) scanf("%d",&b[i]),pos[b[i]]=i;
        for(int i=1;i<=n;i++){
            while(sta.size()&&b[sta.top()]>=b[i]) sta.pop();
            if(sta.empty()) LB[i]=1;
            else LB[i]=sta.top()+1;
            sta.push(i);
        }
        while(sta.size()) sta.pop();
        for(int i=n;i>=1;i--){
            while(sta.size()&&b[sta.top()]>=b[i]) sta.pop();
            if(sta.empty()) RB[i]=n;
            else RB[i]=sta.top()-1;
            sta.push(i);
        }
        bool flag=0;
        int id=n;
        for(int i=1;i<=n;i++){
            if(LA[i]==LB[i]) continue;
            id=i-1;break;
        }
        cout<<id<<endl;
    }
    return 0;
}
