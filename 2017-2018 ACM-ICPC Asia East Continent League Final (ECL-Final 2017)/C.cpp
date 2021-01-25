#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int INF=0x3f3f3f3f;
int a[MAXN], b[MAXN], s[MAXN];
int f[MAXN][125];
int dp[MAXN];
int main () {
	int T,cur=1;
	scanf("%d", &T);
	
	while(T--) {
		int n;
		scanf("%d", &n);
		int sum=0,maxx=0;
		for (int i = 1; i <= n + 1; i ++) scanf("%d", &s[i]),sum+=s[i];
		for (int i = 1; i <= n; i ++) scanf("%d %d", &a[i], &b[i]),maxx=max(maxx,b[i]);
		printf("Case #%d: %d.000000\n",cur++,sum+maxx);
	}
	return 0;
}
