#include<bits/stdc++.h>
 
using namespace std;
stack<char> sta;
int main(){
    string s;
    cin>>s;
    int ans=0;
    for(int i=0;i<(int)s.length();i++){
        if(sta.empty()){
            sta.push(s[i]);
        }
        else{
            if(sta.top()==s[i]){
                if(i+1<(int)s.length()&&sta.top()==s[i+1]){
                    sta.pop();
                    ans++;
                    i++;
                }
                else{
                    if(sta.size()>=2){
                        char x1=sta.top();sta.pop();
                        char x2=sta.top();sta.pop();
                        if(x1==x2&&x1==s[i]) ans++;
                        else{
                            sta.push(x2);
                            sta.push(x1);
                            sta.push(s[i]);
                        }
                    }
                    else sta.push(s[i]);
                }
            }
            else sta.push(s[i]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
