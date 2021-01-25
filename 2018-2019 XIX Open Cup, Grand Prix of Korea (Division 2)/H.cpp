#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 7;

int a[MAXN], r[MAXN];
int ans1[MAXN], ans2[MAXN];
int main () {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)	scanf("%d", &a[i]);
	
	int i, j;
	i = 1, j = 2;
	while (i <= n) {
		if(a[i] <= a[j]) {
			while(j < n && a[j] <= a[j+1])	j++;
			while(i < j) 	r[i++] = j;
			j++;
		} else {
			while(j < n && a[j] > a[j+1])	j++;
			while(i < j)	r[i++] = j;
			j++;
		}
	}
	for(int i = 1; i <= n; ++i)	r[i] = min(n, r[i]);
	memset(ans1, -1, sizeof ans1);
	memset(ans2, -1, sizeof ans2);
	int q, minrun;
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &minrun);
		if(ans1[minrun] != -1) {
			printf("%d %d\n", ans1[minrun], ans2[minrun]);
			continue;
		}
		int sa = 0, bad = 0;
		int index = 1, tmp;
		while(index <= n) {
			tmp = r[index] - index + 1;
			index = r[index] + 1;
			sa++;
			if(tmp < minrun) {
				bad += minrun - tmp;
				index += minrun - tmp;
				if(index > n) bad -= index - n - 1;
			}
		}
		ans1[minrun] = sa; ans2[minrun] = bad;
		printf("%d %d\n", sa, bad);
	}
	return 0;
}
