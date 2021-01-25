#include<bits/stdc++.h>
#define rep(i, a, b)    for(int i = (a); i <= (b); ++i)
#define per(i, a, b)    for(int i = (a); i >= (b); --i)
#define debug(x)    cerr << #x << ' ' << x << endl
using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 7;
const int MOD = 1e9 + 7;

double avg;

struct node {
    double org, time;
    double val;
    friend bool operator < (const node &a, const node &b) {
        return a.time * (1.0 * a.org / a.time - avg) * (1.0 * a.org / a.time - avg) - 
                (a.time + 1) * (1.0 * a.org / (a.time + 1) - avg) * (1.0 * a.org / (a.time + 1) - avg) < 
                b.time * (1.0 * b.org / b.time - avg) * (1.0 * b.org / b.time - avg) - 
                (b.time + 1) * (1.0 * b.org / (b.time + 1) - avg) * (1.0 * b.org / (b.time + 1) - avg);
        // return a.org * (b.time + 1) < b.org * (a.time + 1);
    }
}s[MAXN];

int main() {
    int T, kase = 1;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);
        priority_queue<node> q;
        avg = 0;
        rep(i, 1, n) {
            scanf("%lf", &s[i].org);
            avg += s[i].org;
            s[i].time = 1;
            q.push(s[i]);
        }
        avg /= m;
        m -= n;
        rep(i, 1, m) {
            node t = q.top(); q.pop();
            t.time ++;
            q.push(t);
        }
        m += n;
        rep(i, 1, n) {
            s[i] = q.top(); q.pop();
            s[i].val = 1.0 * s[i].org / s[i].time;
        }
        double ans = 0;
        rep(i, 1, n) ans += s[i].time * (s[i].val - avg) * (s[i].val - avg);
        ans /= m;
        printf("Case #%d: %.12lf\n", kase++, ans);
    }
    return 0;
}
