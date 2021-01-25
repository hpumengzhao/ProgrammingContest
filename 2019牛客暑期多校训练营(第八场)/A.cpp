#include<bits/stdc++.h>
#define rep(i, a, b)    for(int i = (a); i <= (int)(b); ++i)
#define per(i, a, b)    for(int i = (a); i >= (int)(b); --i)
#define debug(x)    cerr << #x << ' ' << x << endl;
using namespace std;
  
typedef long long ll;
const int MAXN = 3e3 + 7;
char mp[MAXN][MAXN];
int a[MAXN], l[MAXN], r[MAXN], up[MAXN][MAXN], sum[MAXN][MAXN], vis[MAXN][MAXN];
  
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    rep(i, 1, n)    scanf("%s", mp[i] + 1);
    rep(i, 1, n){
        rep(j, 1, m){
            if(mp[i][j] == '1') up[i][j] = up[i-1][j] + 1;
            else    up[i][j] = 0;
            sum[i][j] = sum[i][j-1] + (mp[i][j] == '1');
        }
    }
    int ans = 0, cnt = 0;
    rep(j, 1, n){
        cnt++;
        for(int i = 1; i <= m; ++i) a[i] = up[j][i];
        // rep(i, 1, m)    printf("%d%c", a[i], (i == m)?'\n':' ');
        a[0] = a[m+1] = INT_MIN;
        stack<int> sta;
        for(int i = 1; i <= m+1; ++i){
            if(sta.empty() || a[sta.top()] <= a[i]){
                sta.push(i);
            } else {
                while(!sta.empty() && a[sta.top()] > a[i]){
                    r[sta.top()] = i-1;
                    sta.pop();
                }
                sta.push(i);
            }
        }
        //sta只剩下一个a[n+1]
        sta.pop();
        //它没了
        for(int i = m; i >= 0; --i){
            if(sta.empty() || a[sta.top()] <= a[i]){
                sta.push(i);
            } else {
                while(!sta.empty() && a[sta.top()] > a[i]){
                    l[sta.top()] = i+1;
                    sta.pop();
                }
                sta.push(i);
            }
        }
        //sta只剩下一个a[0]
        sta.pop();
        //它没了
        // for(int i = 1; i <= m; ++i) {
        //     cout << l[i] << ((i == m)?'\n':' ');
        // }
        // for(int i = 1; i <= m; ++i) {
        //     cout << r[i] << ((i == m)?'\n':' ');
        // }
        int L, R;
        rep(i, 1, m){
            L = l[i];
            R = r[i];
            if(mp[j][i] == '0') continue;
            if(vis[L][R] == cnt)   continue;
            vis[L][R] = cnt;
            if(sum[j+1][R] - sum[j+1][L-1] != R-L+1)    ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
