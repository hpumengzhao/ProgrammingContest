#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const int maxn=1000000+10;
const int INF=0x3f3f3f3f;
long long cal(long long x){
	if(x<=48) return 0;
	if(x<=56) return 1;
	if(x<=60) return 2;
	if(x<=62) return 3;
	if(x<=63) return 4;
}
int main(){
	int T;
	long long a[5];
	scanf("%d",&T);
	int cas=1;
	while(T--){
		for(int i=0;i<5;i++) scanf("%lld",&a[i]);
		int n;
		long long sum=0;
		scanf("%d",&n);
		long long x;
		for(int i=1;i<=n;i++){
			scanf("%lld",&x);
			sum+=a[cal(x)];
		}
		printf("Case #%d: %lld\n",cas++,sum*10000);
	}	
	return 0;
}
