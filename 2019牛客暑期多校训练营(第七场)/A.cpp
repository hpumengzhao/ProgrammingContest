#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s,t;
bool check(){
    int len=t.length();
    string a=t;
    int pos=0;
    while(pos<len-1){
        a=a.substr(1,len-1);
        a+=t[pos++];
        if(a<t) return false;
    }
    return true;
}
int main()
{
    int q;
    cin >> q;
    while(q--){
        cin >> s;
        int len=s.length();
        int i,j;
        for(i=0;i<len;i++){
            t="";
            for(j=i;j<len;j++) t+=s[j];
            for(j=len-1;j>=i;j--){
                // cout << "t=" << t << endl;
                if(check()){
                    cout << t << " ";
                    i=j;
                    break;
                }
                t=t.substr(0,j-i);
            }
        }
        cout << endl;
    }
    return 0;
}
