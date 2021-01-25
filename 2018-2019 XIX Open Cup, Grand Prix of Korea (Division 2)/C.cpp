#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 7;

vector<ll> v;
map<ll, bool> vis;
void dfs(ll n) {
	if(vis[n] || n == 1)	return;
	vis[n] = 1;
	v.push_back(n);
	dfs(n/2); dfs((n+1)/2);
}
int main () {
	int T;
	scanf("%d", &T);
	while(T--) {
		v.clear(); vis.clear();
		ll n;
		scanf("%lld", &n);
		map<ll, int> pos;
		dfs(n);
		pos[1] = 0;
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		int sz = v.size();
		printf("%d\n", sz + 1);
		printf("-1 -1\n");
		int cnt = 1;
		for(int i = 0; i < sz; ++i) {
			printf("%d %d\n", pos[(v[i]+1)/2], pos[v[i]/2]);
			if(pos[v[i]] == 0)	pos[v[i]] = cnt++;
		}
		printf("%d\n", cnt-1);
	}
	return 0;
}
