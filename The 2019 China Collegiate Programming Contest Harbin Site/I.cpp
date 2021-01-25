#include<bits/stdc++.h>

using namespace std;
const int N = 1e6+100;
const int mod =1e9+7;
long long h[N];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		bool flag=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&h[i]);
			if(h[i]>=n){
				flag=1;
			}
			if(h[i]<h[i-1]){
				flag=1;
			}
		}
		if(h[n]!=n-1) flag=1;
		if(h[1]!=0) flag=1;
		if(h[2]==0) flag=1;
		if(flag){
			puts("0");continue;
		}
		long long ans=1;
		long long cnt=0;
		for(int i=2;i<=n;i++){
			if(h[i]!=h[i-1]){
				cnt+=h[i]-h[i-1]-1;
				ans*=2;
				ans%=mod;
			}else{
				ans*=(cnt)%mod;
				ans%=mod;
				cnt--;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
