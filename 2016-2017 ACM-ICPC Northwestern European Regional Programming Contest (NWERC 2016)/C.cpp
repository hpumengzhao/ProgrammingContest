#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 7;
const double eps = 1e-10;
struct shield{
	double l, r, rate;
}s[MAXN],ns[MAXN];

bool cmp(shield x, shield y) {
	return x.r < y.r;
}
double x, y;
int n;
int main () {
	cin >> x >> y >> n;
//	if(x<0) x=-x;
	for(int i=1;i<=n;i++){
		cin>>s[i].l>>s[i].r>>s[i].rate;
	}
	sort(s+1,s+n+1,cmp);
	double ans=0;
	for(int i=1;i<=n;i++){
		ans+=(s[i].l-s[i-1].r);
		ans+=(s[i].r-s[i].l)*s[i].rate;
	}
	ans+=(y-s[n].r);
	printf("%.14lf\n",x/ans);
	return 0;
}
