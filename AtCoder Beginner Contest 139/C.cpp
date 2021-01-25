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
int L[N],R[N],a[N];
int main(){
    //freopen("1.in", "r", stdin);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=0;
    int cnt=1;
    int now=a[1];
    for(int i=2;i<=n;i++){
        if(a[i]<=now){
            cnt++;
            now=a[i];
        }
        else{
            ans=max(ans,cnt);
            cnt=1;
            now=a[i];
        }
    }
    ans=max(ans,cnt);
    cout<<ans-1<<endl;
    return 0;
}
