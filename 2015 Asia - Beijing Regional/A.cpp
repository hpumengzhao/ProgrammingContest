#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 1e6 + 7;
ll a[MAXN];
int main () {
	int T;
	scanf("%d", &T);
	while(T--) {
		int R, n;
		scanf("%d %d", &R, &n);
		for(int i = 0; i <= R + 7; ++i)	a[i] = 0;
		ll x, y, w, h;
		ll all = 0;
		for(int i = 1; i <= n; ++i) {
			scanf("%lld %lld %lld %lld", &x, &y, &w, &h);
			a[x] += h; a[x + w] -= h;
			all += 1LL * w * h;
		}
//		for(int i = 0; i <= R; ++i) printf("%d ", a[i]);
//		printf("\n");
		for(int i = 1; i <= R; ++i) a[i] += a[i-1];
		for(int i = 1; i <= R; ++i) a[i] += a[i-1];
//		for(int i = 0; i <= R; ++i) printf("%d ", a[i]);
//		printf("\n");
//		cerr << all << endl;s
		ll ans = -1, dif = 1LL<<60;
		for(int i = 0; i <= R; ++i) {
			if(abs(all - 2 * a[i]) <= dif) {
				ans = i;
				dif = abs(all - 2 * a[i]);
			}
		}
		printf("%d\n", min((ll)R, ans + 1));
	}
	return 0;
}
