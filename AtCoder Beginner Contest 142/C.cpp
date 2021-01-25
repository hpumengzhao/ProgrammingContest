#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+100;
struct node{
    int num;
    int id;
}p[N];
bool cmp(node a,node b){
    return a.num<b.num;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
         cin>>p[i].num;
         p[i].id=i;
    }
    sort(p+1,p+n+1,cmp);
    for(int i=1;i<=n;i++){
        cout<<p[i].id<<' ';
    }
    cout<<endl;
    return 0;
}
