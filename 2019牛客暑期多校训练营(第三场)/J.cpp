#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
unordered_map<string,list<pair<string,ll>>::iterator > val;//str str & data
list<pair<string,ll>> blocks;//str & data
int main(){
    //freopen("1.in","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        val.clear();blocks.clear();
        int n,m;scanf("%d %d",&n,&m);
        long long op,v;char id[30];
        for(int i=1;i<=n;i++){
            scanf("%lld %s %lld",&op,id,&v);
            //cout<<"q: "<<id<<endl;
            if(op==1){
                auto it=val.find(id);
                if(it==val.end()){//没找到
                    puts("Invalid");continue;
                }
                auto p=it->second;
                if(v==-1){
                    if(p==blocks.begin()){
                        puts("Invalid");continue;
                    }
                    --p;
                    printf("%lld\n",p->second);
                }
                if(v==0){
                    printf("%lld\n",p->second);
                }
                if(v==1){
                    ++p;
                    if(p==blocks.end()){
                        puts("Invalid");
                        continue;
                    }
                    printf("%lld\n",p->second);
                }
            }
            else{
                auto it=val.find(id);
                if(it==val.end()){
                    //cout<<"dsad"<<endl;
                    if(blocks.size()==m){
                        val.erase(blocks.begin()->first);
                        blocks.pop_front();
                    }
                    printf("%lld\n",v);
                    blocks.emplace_back(make_pair(id,v));
                    val[id]=--blocks.end();
                }
                else{
                    long long x=it->second->second;
                    printf("%lld\n",x);
                    blocks.erase(it->second);
                    blocks.emplace_back(make_pair(id,x));
                    val[id]=--blocks.end();
                }
            }
        }
    }
    return 0;
}
