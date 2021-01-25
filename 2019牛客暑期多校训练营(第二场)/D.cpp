#include<bits/stdc++.h>
using namespace std;
const int maxn=100+10;
#define ll long long
bitset<maxn>mp[maxn];
ll w[maxn];
ll n,k;
char str[maxn];
struct node{
    bitset<maxn>g;
    ll last;
    ll sum;
    ll w;
    bool friend operator < (node i,node j){
        return i.w>j.w;
    }
};
void bfs(){
    if(k==0) {
        printf("0\n");
        return ;
    }
    priority_queue<node>que;
    bitset<maxn>q;
    q.reset();
    for(ll i=0;i<n;i++){
        q[i]=1;
        que.push((node){q,i,1ll,w[i]});
        q[i]=0;
    }
    node x;
    while(!que.empty()){
        x=que.top();
        que.pop();
        k--;
        if(k==0){
            printf("%lld\n",x.w);
            return ;
        }
        for(ll i=x.last+1;i<n;i++){
//          node z;
            if((mp[i] & x.g).count()==x.sum){
                q[i]=1;
                que.push((node){x.g|q,i,x.sum+1,x.w+w[i]});
                q[i]=0;
            }
        }
    }
    printf("-1\n");
}
int main()
{
    scanf("%lld %lld",&n,&k);
    k--;
    for(ll i=0;i<n;i++){
        scanf("%lld",&w[i]);
    }
    for(ll i=0;i<n;i++){
        scanf("%s",str);
        for(ll j=0;j<n;j++){
            mp[i][j]=str[j]-'0';
        }
    }
    bfs();
    return 0;
}
