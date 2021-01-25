#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+100;
const int mod = 1e9+7;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f3f;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define fep(i,a,b) for(int i=(a);i>=(b);i--)
inline bool read(ll &num) {
    char in;bool IsN=false;
    in=getchar();
    if(in==EOF) return false;
    while(in!='-'&&(in<'0'||in>'9')) in=getchar();
    if(in=='-'){ IsN=true;num=0;}
    else num=in-'0';
    while(in=getchar(),in>='0'&&in<='9'){
            num*=10,num+=in-'0';
    } 
    if(IsN) num=-num;
    return true;
}
pair<int,int> a[N];
map<pair<int,int>,int> mp1,mp2;
int main(){
    int n;cin>>n;
    if(n==1){
        puts("0");return 0;
    }
    rep(i,1,n){
        cin>>a[i].first>>a[i].second;
        mp1[{2*a[i].first,2*a[i].second}]++;
    }
    rep(i,1,n){
        rep(j,i+1,n){
            mp2[{a[i].first+a[j].first,a[i].second+a[j].second}]++;
        }
    }
    int ans=INF;
    for(auto v:mp2){
        ans=min(ans,n-2*mp2[v.first]-mp1[v.first]);
    }
    cout<<ans<<endl;
    return 0;
}
