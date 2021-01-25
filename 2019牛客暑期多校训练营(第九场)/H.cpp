#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
struct node {
    int l, r;
    ll sum, num;
}tree[N * 22];
int n, q;
int h[N];
int root[N], tot;
ll sum[N];
int update(int pre, int l, int r, int pos) {
    int cur = ++tot;
    tree[cur].l = tree[pre].l;
    tree[cur].r = tree[pre].r;
    tree[cur].sum = tree[pre].sum;
    tree[cur].num = tree[pre].num;
    tree[cur].sum += pos;
    tree[cur].num++;
    if(l == r) return cur;
    int mid = (r + l) >> 1;
    if(pos <= mid) tree[cur].l = update(tree[pre].l, l, mid, pos);
    else tree[cur].r = update(tree[pre].r, mid + 1, r, pos);
    return cur;
}
ll cntsum, cntnum;
void query(int pl, int pr, int l, int r, int pos) {
    if(pos <= l) {
        cntsum += tree[pr].sum - tree[pl].sum;
        cntnum += tree[pr].num - tree[pl].num;
        return;
    }
    int mid = (r + l) >> 1;
    if(pos <= mid) query(tree[pl].l, tree[pr].l, l, mid, pos);
    query(tree[pl].r, tree[pr].r, mid + 1, r, pos);
}
int main() {
    int l, r, x, y;
    int ll, rr, mid, ans;
    double cnt, ans_;
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &h[i]);
        sum[i] = sum[i - 1] + h[i];
        root[i] = update(root[i - 1], 1, 100000, h[i]);
    }
    double tmp;
    while(q--) {
        scanf("%d %d %d %d", &l, &r, &x, &y);
        cnt = 1.0 * (sum[r] - sum[l - 1])  * x / y;
           
        ll = 1, rr = 100000;
        while(ll <= rr) {
            mid = (rr + ll ) >> 1;
            cntsum = 0;
            cntnum = 0;
            query(root[l - 1], root[r], 1, 100000, mid);
            if(cntsum - cntnum * (mid - 1) >= cnt) {
                ans = mid;
                ans_ = cntsum - cntnum * (mid - 1);
                tmp = cntnum;
                ll = mid + 1;
            } else {
                rr = mid - 1;
            }
        }
        if(ans != 100000) {
            cntsum = 0, cntnum = 0;
            query(root[l - 1], root[r], 1, 100000, ans + 1);
            ans_ = cntsum - cntnum * ans;
        } else {
            ans_ = 0;
        }
        printf("%.15f\n", ans - (cnt - ans_) / tmp);
    }
    return 0;
}
