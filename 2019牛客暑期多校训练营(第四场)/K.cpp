#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int MAXN = 2e5 + 7;
ll a[MAXN][3];
 
int main(){
    string s;
    cin >> s;
    ll ans = 0;
    for(int i = 1; i <= s.size(); ++i){
        int ch = s[i-1] - '0';
        for(int j = 0; j < 3; ++j){
            a[i][(j+ch)%3] = a[i-1][j];
        }
        a[i][ch%3]++;
        if(i >= 2 && s[i-1] == '0' && s[i-2] == '0')    ans += a[i][0];
        else if(s[i-1] == '0')  ans++;
    }   
    cout << ans << endl;
    return 0;
}
