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
int nxt[N][27];
void init(char *s){
    int l=strlen(s);
    for(int i=0;i<26;i++) nxt[l][i]=INF;
    for(int i=l-1;i>=0;i--){
        for(int j=0;j<26;j++){
            nxt[i][j]=nxt[i+1][j];
        }
        nxt[i][s[i]-'a']=i;
    }
}
char s[N],t[N];
int main(){
    //freopen("1.in", "r", stdin);
    int n,m;
    cin>>n>>m;
    scanf("%s %s",s,t);
    init(s);
    int pos=-1;
    int ans=0;
    int cnt=0;
    bool flag=0;
    vector<int> id;
    for(int i=0;i<n;i++){
        for(int j=t[cnt]-'a'+1;j<26;j++){
            if(nxt[i][j]!=INF){
                flag=1;
                ans=max(ans,cnt+n-nxt[i][j]);
            }
        }
        if(s[i]==t[cnt]){
            cnt++;
            id.push_back(i);
        }
        if(cnt==m) break;
    }
    if(!flag){
        if(id.size()==m){
            if(id[m-1]==n-1)cout<<-1<<endl;
            else cout<<m+(n-id[m-1]-1)<<endl;
        }
        else cout<<-1<<endl;
    }
    else{
        if(id.size()==m&&id[m-1]!=-1){
            ans=max(ans,m+(n-id[m-1]-1));
        }
        cout<<ans<<endl;
    }
    return 0;
}
