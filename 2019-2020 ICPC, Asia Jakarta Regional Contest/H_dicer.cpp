#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int MAXN = 2e5 + 7;
struct node{
	ll l, w;
	ll ol, ow;
	ll area;
}s[MAXN];
bool cmp(node x, node y) {
	if(x.l == y.l)	return x.w < y.w;
	return x.l < y.l;
}
struct BIT{
	ll e[MAXN], a[MAXN];
	int lowbit(int x){
		return x & -x;
	}
	void upd(int x) {
		int lx;
		while(x <= 200000) {
			e[x] = a[x];
			lx = lowbit(x);
			for(int i = 1; i <lx; i <<= 1) e[x] = max(e[x], e[x-i]);
			x += lowbit(x);
		}
	}
	ll get(int l, int r) {
		ll ans = 0;
		while (r >= l) {
			ans = max(a[r], ans);
			r--;
			while(r >= l + lowbit(r)) {
				ans = max(e[r], ans);
				r -= lowbit(r);
			}
		}
		return ans;
	}
}bit, bit2;
vector<int> v;
int get(int x) {
	return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}
int main () {
	int n;
	scanf("%d", &n);
	ll ans = 0;
	for(int i = 1; i <= n; ++i) {
		scanf("%lld %lld", &s[i].l, &s[i].w);
		if(s[i].l > s[i].w)	swap(s[i].l, s[i].w);
		s[i].ol = s[i].l; s[i].ow = s[i].w;
		s[i].area = 1ll * s[i].l * s[i].w;
		v.push_back(s[i].l); v.push_back(s[i].w);
		ans = max(ans, s[i].l * s[i].w);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for(int i = 1; i <= n; ++i) {
		s[i].l = get(s[i].l);
		s[i].w = get(s[i].w);
	}
	sort(s+1, s+1+n,cmp);
	for(int i = 1; i <= n; ++i) {
		ans = max(ans,  bit.get(1, s[i].w)*2);
		ans = max(ans,  2*s[i].ow * bit2.get(s[i].w, 200000));
		bit.a[s[i].w] = s[i].area;
		bit.upd(s[i].w);
		bit2.a[s[i].w] = s[i].ol;
		bit2.upd(s[i].w);
	}
	if(ans&1){
	    printf("%lld.5\n",ans/2);
	}else{
	    printf("%lld.0\n",ans/2);
	}
	return 0;
}
