#include<bits/stdc++.h>
 
using namespace std;
char apl[16]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
string change(string s){
    int l=s.length();
    string now="";
    for(int i=0;i<16;i+=4){
        int kk=0;
        for(int j=i;j<i+4;j++){
            kk=kk*2+s[j]-'0';
        }
        now+=apl[kk];
    }
    return now;
}
struct node{
    int l,r,num;//[l,r]内0的数量
};
bool cmp(string a,string b){
    if(a.length()==b.length()) return a<b;
    return a.length()<b.length();
}
int main(){
    int T;
    int cas=1;
    scanf("%d",&T);
    while(T--){
        vector<string> b16;
        vector<string> prs;
        vector<string> mids;
        vector<node> seg;
        vector<string> ans;
        string s;
        cin>>s;
        for(int i=0;i<128;i+=16){
            string now="";
            for(int j=i;j<i+16;j++){
                now+=s[j];
            }
            b16.push_back(now);
        }
        for(auto v:b16){
            prs.push_back(change(v));
        }
        for(auto v:prs){
            int id=-1;
            for(int i=0;i<4;i++){
                if(v[i]!='0'){
                    id=i;break;
                }
            }
            string now;
            if(id==-1){
                now="0";
            }
            else{
                for(int i=id;i<4;i++){
                    now+=v[i];
                }
            }
            mids.push_back(now);
        }
        int num=0;
        int nowl=-1;int nowr=-1;
        int maxx=0;
        for(int i=0;i<(int)mids.size();i++){
            if(mids[i]=="0"){
                num++;
            }
            else{
                if(num){
                    maxx=max(maxx,num);
                    nowr=i-1;nowl=i-num;
                    seg.push_back({nowl,nowr,num});
                    num=0;
                }
            }
        }
        nowr=(int)mids.size()-1;
        nowl=nowr-num+1;
        maxx=max(maxx,num);
        printf("Case #%d: ",cas++);
        seg.push_back({nowl,nowr,num});
        if(maxx<2){
            cout<<mids[0];
            for(int i=1;i<(int)mids.size();i++){
                cout<<":"<<mids[i];
            }
            cout<<endl;continue;
        }
        for(auto v:seg){
            string reg="";
            if(v.num==maxx){
                for(int i=0;i<v.l-1;i++){
                    reg+=mids[i];
                    reg+=":";
                }
                if(v.l-1>=0) reg+=mids[v.l-1];
                reg+="::";
                for(int i=v.r+1;i<mids.size()-1;i++){
                    reg+=mids[i];
                    reg+=":";                  
                }
                if(mids.size()-1>v.r) reg+=mids[mids.size()-1];
                ans.push_back(reg);
            }
        }
        sort(ans.begin(),ans.end(),cmp);
        cout<<ans[0]<<endl;
    }
    return 0;
}
