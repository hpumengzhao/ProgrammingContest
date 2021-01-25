#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define per(i, a, b) for(int i = (a); i >= (b); --i)
using namespace std;
 
const int MAXN = 3007;
const int MOD = 998244353;
int n, m, dp[MAXN][MAXN], C[MAXN][MAXN];
char s[MAXN], t[MAXN];
void add(int &x, int v){
    x += v;
    if(x >= MOD) x-= MOD;
}
void init(){
    C[0][0] = 1;
    rep(i, 1, 3000){
        C[i][0] = 1;
        rep(j, 1, i){
            C[i][j] = C[i-1][j-1] + C[i-1][j];
            if(C[i][j] >= MOD)  C[i][j] -= MOD;
        }
    }
}
void solve(){
    int ans = 0;
    rep(i, m+1, n){
        rep(j, 1, n){
            if(s[j] != '0')    add(ans, C[n-j][i-1]);
        }
    }
    rep(i, 1, n + 1){
        rep(j, 1, m + 1){
            dp[i][j] = 0;
        }
    }
    per(i, n, 1){
        per(j, m, 1){
            add(dp[i][j], dp[i+1][j]);
            if(s[i] > t[j]){
                add(dp[i][j], C[n-i][m-j]);
            } else if(s[i] == t[j]){
                add(dp[i][j], dp[i+1][j+1]);
            }
        }
    }
    printf("%d\n", (ans + dp[1][1]) % MOD);
}
int main(){
    init();
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &n, &m);
        scanf("%s %s", s + 1, t + 1);
        solve();
    }
    return 0;
}
