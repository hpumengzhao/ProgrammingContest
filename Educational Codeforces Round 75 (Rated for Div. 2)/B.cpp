#include<bits/stdc++.h>

using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        int n1,n0;
        n1=n0=0;
        int n;
        cin>>n;
        bool check=0;
        for(int i=1;i<=n;i++){
            cin>>s;
            for(char c:s){
                if(c=='1') n1++;
                else n0++;
            }
            int len=(int)s.length();
            if(len&1) check=1;
        }
        int ans=(!check&&(n0&1)&&(n1&1))?n-1:n;
        cout<<ans<<endl;
    }
    return 0;
}
