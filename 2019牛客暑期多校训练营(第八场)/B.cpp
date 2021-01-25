#include<bits/stdc++.h>
#define rep(i, a, b)    for(int i = (a); i <= (int)(b); ++i)
#define per(i, a, b)    for(int i = (a); i >= (int)(b); --i)
#define debug(x)    cerr << #x << ' ' << x << endl;
using namespace std;
 
typedef long long ll;
const int MAXN = 1e6 + 7;
 
int a[MAXN], cnt[MAXN];
int main() {
    int n;
    scanf("%d", &n);
    ll res = 0;
    rep(i, 1, n){
        scanf("%d", &a[i]);
        res += 1LL * (n - i + 1) * (i - cnt[a[i]]);
        cnt[a[i]] = i;
    }
    printf("%lld\n", res);
    return 0;
}
