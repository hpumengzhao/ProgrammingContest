#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF=1e18;
ll pows[17];
void init1(){
    pows[0]=1;
    for(int i=1;i<=16;i++) pows[i]=pows[i-1]*10;
}
ll add(ll a,ll b){
    int lena=0;
    int lenb=0;
    ll resa=a;
    ll resb=b;
    while(b){
        lenb++;
        b/=10;
    }
    while(a){
        lena++;
        a/=10;
    }
    if(lena+lenb>16) return INF;
    resa*=(ll)pows[lenb];
    resa+=resb;
    return resa;
}
vector<ll> all;
ll qpow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) ans=ans*a;
        a=a*a;
        b>>=1;
    }
    return ans;
}

void init(){
    ll lim=100000;
    ll d[11]={0};
    ll flag=0;
    for (ll len=3;len<=15;len++){
        for(ll i=1;i<=lim;i++){
            for(ll q1=2;;q1++){
                for(ll q2=1;q2<=q1-1;q2++){
                    ll s=0;
                    for (ll j=1;j<=len;j++){
                        d[j]=i*qpow(q1,j-1);
                        d[j]=d[j]*qpow(q2,len-j);
                        s=add(s,d[j]);
                        if (s==INF){
                            flag++;
                            break;
                        }
                    }
                    if (flag==1){
                        if (q2==1) flag++;
                        break;
                    }
                    else flag=0,all.push_back(s);
                }
                if(flag==2){
                    if (q1==2) flag++;
                    break;
                }else flag=0;
            }
            if (flag==3){
                if (i==1) flag++;
                break;
            }else flag=0;
        }
        if (flag==4){
            break;
        }
    }
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());
}
int main(){
    init1();
    init();
    int T;
    int cas=1;
    scanf("%d",&T);
    while(T--){
        ll L,R;scanf("%lld %lld",&L,&R);
        ll RR=upper_bound(all.begin(),all.end(),R)-all.begin();
        ll LL=lower_bound(all.begin(),all.end(),L)-all.begin();
        // cout<<all[RR]<<' '<<all[LL]<<endl;
        printf("Case #%d: %lld\n",cas++,RR-LL);
    }
    return 0;
}
