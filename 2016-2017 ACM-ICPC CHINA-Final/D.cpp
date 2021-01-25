#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e5+100;
int T,n,K;
ll a[N],res[N],maxx;
int pos[N];
bool check2(int num){
	for(int i=1;i<=n;i++) pos[i]=0;
	for(int i=1;i<=num;i++) pos[i]=1;
	int cur=num+1,sum=0;
	for(int i=1;i<=n;i++){
		if(!pos[i]) continue;
		while(cur<=n && a[i]*2>a[cur]) cur++;
		if(cur<=n) pos[cur]=pos[i]+1;
		if(pos[i]==K) sum++;
		cur++;
	}
	return sum>=num;
}
int main() {
	int cas=1;
	scanf("%d",&T);
	while(T--){
		maxx=0;
		scanf("%d %d",&n,&K);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			maxx=max(maxx,a[i]);
		}
		sort(a+1,a+n+1);
		int l=0,r=n/K;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check2(mid)) l=mid+1;
			else r=mid-1;
		}
		printf("Case #%d: %d\n",cas++,l-1);
	}
	return 0;
}
