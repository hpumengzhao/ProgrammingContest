#include<bits/stdc++.h>
using namespace std;

map<pair<int, int>, bool> vis;
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T, kase = 1;
	cin >> T;
	while (T--) {
		int n, k, x, y;
		vector<pair<int, int> > v;
		cin >> n >> k;
		int up = 9 + 2 * ( n-2) * 4 + (n-1)*(n-2)/2*5, down = 12 + 4 * ( n-2) * 4 + (n-2)*(n-2)*5;
		for(int i = 1; i <= k; ++i) {
			cin >> x >> y; x++; y++;
			vis[{x,y}] = 1;
			v.push_back({x, y});
			if(x == 1 && y == n)	up -= 3, down -= 3;
			else if(x == 1 && y == 1) down -= 3;
			else if(x == n && y == 1)	up -= 3, down -= 3;
			else if(x == n && y == n)	up -= 3, down -= 3;
			else if(x == 1 || y == 1)	down -= 4;
			else if(x == n || y == n)	up -= 4, down -= 4;
			else if(x + y >= n + 1)	up -= 5, down -= 5;
			else down -= 5;
		}
		for(pair<int, int> p: v){
			x = p.first, y = p.second;
			if(x + 1 <= n && vis[{x+1,y}] == 0) {
				down--;
				if(x + 1 + y >= n + 1)	up--;
			}
			if(x-1 >= 1 && vis[{x-1,y}] == 0) {
				down--;
				if(x - 1 + y >= n + 1)	up--;
			}
			if(y-1 >= 1 && vis[{x,y-1}] == 0) {
				down--;
				if(x + y - 1 >= n + 1)	up--;
			}
			if(y + 1 <= n && vis[{x,y+1}] == 0) {
				down--;
				if(x + y + 1 >= n + 1)	up--;
			}
		}
		int g = __gcd(up, down);
		up /= g; down /= g;
		cout << "Case #" << kase++ << ": ";
		cout << up << "/" << down << endl;
		vis.clear();
	}
	return 0;
}
