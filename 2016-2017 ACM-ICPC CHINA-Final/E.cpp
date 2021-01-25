#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10;
struct node{
	long double x,y;
}a[maxn];
bool cmp(node i,node j){
	return i.y*j.x>j.y*i.x;
}
int main () {
	int t,cur=1,n;
	char qq;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i].x>> qq >>a[i].y;
		}
		sort(a+1,a+n+1,cmp);
		int res=0;
		long double sum=0.0;
		for(int i=1;i<=n;i++){
			sum+=a[i].x/(a[i].x+a[i].y);
			if(sum>=1.0) break;
			res++;
		}
		printf("Case #%d: %d\n",cur++,res);
	}
	return 0;
}
