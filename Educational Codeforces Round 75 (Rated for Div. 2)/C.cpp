#include<bits/stdc++.h>

using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        queue<char> od,ev;
        for(char c:s){
            if((c-'0')&1) od.push(c);
            else ev.push(c);
        } 
        while(!od.empty()||!ev.empty()){
            if(od.empty()){
                cout<<ev.FRONT();
                ev.pop();
                continue;
            }
            if(ev.empty()){
                cout<<od.FRONT();
                od.pop();
                continue;
            }
            if(od.FRONT()>=ev.FRONT()){
                cout<<ev.FRONT();
                ev.pop();
            }else{
                cout<<od.FRONT();
                od.pop();
            }
        }
        cout<<endl;
    }
    return 0;
}
