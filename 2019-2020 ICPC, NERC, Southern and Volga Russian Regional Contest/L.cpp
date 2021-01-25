#include<bits/stdc++.h>

using namespace std;

int a, b, c;
int ta, tb, tc;
int m(){
	return max(ta, max(tb, tc));
}
bool ok(int x) {
	ta = a; tb = b; tc = c;
	if(m() <= x)	return 1;
	if(ta > x)	return 0;
	if(tc <= x) {
		int tmp = tb - x;
		tb = x;
		tmp -= x - ta;
		ta = x;
		if(tmp <= 0)	return 1;
		tmp -= x - tc;
		tc = x;
		if(tmp <= 0)	return 1;
		return 0;
	} else {
		int b1 = tb;
		int b2 = tc - x;
		tc = x;
		tb = b1 + b2;
		if(m() <= x)	return 1;
		if(b2 > x)	return 0;
		ta += b1 + b2 - x;
//		cerr << ta << ' ' << tb << ' ' << tc << endl;
		if(ta > x)	return 0;
		else	return 1;
	}
}
int main() {
	int T;
	cin >> T;
	while(T--){
		cin >> a >> b >> c;
		if(a > c)	swap(a, c);
		int l = 1, r = 1000, mid;
		while(l <= r) {
			mid = l + r >> 1;
			if(ok(mid))	r = mid - 1;
			else	l = mid + 1;
		}
		cout << l << endl;
	}
	return 0;
}
