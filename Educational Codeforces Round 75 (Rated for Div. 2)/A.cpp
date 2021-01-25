#include<bits/stdc++.h>

using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        set<char> ans;
        int l=(int)s.length();
        char c=s[0];
        int now=1;
        for(int i=1;i<l;i++){
            if(s[i]==c){
                now++;
            }else{
                if(now&1) ans.insert(c);
                c=s[i];
                now=1;
            }
        }
        if(now&1) ans.insert(c);
        for(char c:ans) cout<<c;
    }
    return 0;
}
