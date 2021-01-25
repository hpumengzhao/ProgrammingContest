#include<bits/stdc++.h>
#define ls x<<1
#define rs x<<1|1
using namespace std;
 
typedef long long ll;
const int MAXN = 1e5 + 7;
const int MOD = 1e9 + 7;
char str[MAXN];
 
struct node{
		ll a, b;
		friend node operator * (const node &x, const ll &t) {
			node res;
			res.a = x.a * t % MOD;
			res.b = x.b * t % MOD;
			return res;
		}
		friend node operator + (const node &x, const node &y) {
			node res;
			res.a = (x.a + y.a) % MOD;
			res.b = (x.b + y.b) % MOD;
			return res;
		}
	};
struct p{
	node A, B;
	friend p operator + (const p &x, const p &y) {
		p res;
		res.A = x.A * y.A.a + x.B * y.A.b;
		res.B = x.A * y.B.a + x.B * y.B.b;
		return res;
	}
	void flip() {
		swap(A.a, A.b);
		swap(B.a, B.b);
		swap(A, B);
	}
	void print() {
		printf("((%d %d), (%d %d))\n", A.a, A.b, B.a, B.b);
	}
};
struct Node{
	p P;
	int l, r;
	int mid(){
		return (l+r)>>1;
	}
	bool lz;
}s[MAXN<<2];
struct ST{
	void push_down(int x) {
		if(s[x].lz) {
			s[ls].lz ^= 1; s[rs].lz ^= 1;
			s[ls].P.flip(); s[rs].P.flip();
			s[x].lz = 0;
		}
	}
	void push_up(int x) {
		s[x].P = s[ls].P + s[rs].P;
	}
	void build(int l, int r, int x) {
		s[x].l = l; s[x].r = r; s[x].lz = 0;
		if(l == r) {
			if(str[l] == 'A') {
				s[x].P = {{1, 1}, {0, 1}};
			} else s[x].P = {{1, 0}, {1, 1}};
			return;
		}
		int mid = s[x].mid();
		build(l, mid, ls); build(mid+1, r, rs);
		push_up(x);
	}
	p get(int l, int r, int x) {
		if(s[x].l == l && s[x].r == r) {
			return s[x].P;
		}
		push_down(x);
		int mid = s[x].mid();
		if(l > mid) return get(l, r, rs);
		else if(r <= mid)	return get(l, r, ls);
		else	return get(l, mid, ls) + get(mid + 1, r, rs);
	}
	void upd(int l, int r, int x) {
		if(s[x].l == l && s[x].r == r) {
			s[x].P.flip();
			s[x].lz ^= 1;
			return;
		}
		push_down(x);
		int mid = s[x].mid();
		if(l > mid) upd(l, r, rs);
		else if(r <= mid)	upd(l, r, ls);
		else {
			upd(l, mid, ls);
			upd(mid + 1, r, rs);
		}
		push_up(x);
	}
}st;
int main () {
	int n, q;
	scanf("%d %d %s", &n, &q, str+1);
	st.build(1, n, 1);
	int op, l, r, a, b;
	while(q--){
		scanf("%d %d %d", &op, &l, &r);
		if(op == 1) {
			st.upd(l, r, 1);
		} else {
			scanf("%d %d", &a, &b);
			p ans = st.get(l, r, 1);
			printf("%lld %lld\n", (ans.A.a * a + ans.A.b * b) % MOD, (ans.B.a * a + ans.B.b * b) % MOD);
		}
	}
	return 0;
}
