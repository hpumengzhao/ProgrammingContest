#include<bits/stdc++.h>

using namespace std;
const int N = 1e6+100;
long long w[N],len[N];
int x[N],y[N],c[N],n,T,k,xx,op;
vector<int> all[N];
unordered_map<int,long long> counts;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            all[i].clear();
            c[i]=w[i]=len[i]=0;
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&op);
            if(op==1){
                scanf("%d",&k);
                counts.clear();
                int id;long long maxx=0;
                bool flag=0;
                for(int j=1;j<=k;j++){
                    scanf("%d",&xx);
                    all[i].push_back(xx);
                    counts[xx]++;
                    if(counts[xx]>maxx){
                        maxx=counts[xx];
                        id=xx;
                        flag=0;
                    }
                    else if(counts[xx]==maxx){
                        flag=1;
                    }
                }
                if(!flag){
                    w[i]=max(maxx-(k-maxx),0LL);
                    c[i]=id;
                }
                len[i]=k;
            }else{
                scanf("%d %d",&x[i],&y[i]);
                len[i]=len[x[i]]+len[y[i]];
                if(c[x[i]]==c[y[i]]){
                    c[i]=c[x[i]];
                    w[i]=w[x[i]]+w[y[i]];
                    continue;
                }
                if(w[x[i]]>w[y[i]]){
                    c[i]=c[x[i]];
                    w[i]=w[x[i]]-w[y[i]];
                    continue;
                }
                c[i]=c[y[i]];
                w[i]=w[y[i]]-w[x[i]];
            }
        }
        for(int i=1;i<=n;i++) w[i]=0;
        for(int i=1;i<=n;i++){
            if(all[i].size()){
                for(int v:all[i]){
                    if(v==c[n]) w[i]++;
                }
            }else{
                w[i]=w[x[i]]+w[y[i]];
            }
        }
        if(2*w[n]<=len[n]){
            printf("%lld\n",len[n]);
        }else{
            printf("%lld\n",2*(len[n]-w[n]));
        }
    }
    return 0;
}
