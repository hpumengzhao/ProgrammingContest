#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N =  2e5+100;
ll L[N],R[N],T,n,s;
bool Cmp(pair<ll,ll> a,pair<ll,ll> b){
    return a.first<b.first;
}
bool Check(ll med){
    ll need=0;
    int cnt=0;
    vector<ll> maybe;
    for(int i=1;i<=n;i++){
        if(L[i]>=med){
            cnt++;
            need+=L[i];
        }
        else if(R[i]<med){
            need+=L[i];
        }else{
            need+=med;
            maybe.push_back(L[i]);
            cnt++;
        }
    }
    if(cnt<(n+1)/2) return 0;
    for(ll v:maybe){
        if(cnt>(n+1)/2){
            need+=(v-med);//还回去
            cnt--;
        }else break;
    }
    return need<=s;
}
ll Solve(ll L,ll R){
    bool flag=0;
    for(int i=1;i<=80;i++){
        ll mid=(L+R)>>1;
        if(Check(mid)){
            L=mid;
            flag=1;
        }else R=mid;
    }
    if(flag){
        return L;
    }else return -1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--){
        vector<pair<ll,ll>> ps;
        cin>>n>>s;
        for(ll i=1;i<=n;i++){
            cin>>L[i]>>R[i];
            ps.push_back({L[i],R[i]});
        }
        sort(ps.begin(),ps.end(),Cmp);
        for(int i=0;i<n;i++){
            L[i+1]=ps[i].first;
            R[i+1]=ps[i].second;
        }
        ll ans=Solve(0,(ll)1e18);
        cout<<ans<<endl;
    }
    return 0;
}
