#include<bits/stdc++.h>

using namespace std;
const int N = 4e4+100;
long long dp[N],a[N],b[N];
int main(){
	int h,n;
	cin>>h>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<=N-1;i++) dp[i]=(1e18);
	dp[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=a[i];j<=h+10000;j++){
			dp[j]=min(dp[j],dp[j-a[i]]+b[i]);
		}
	} 
	long long ans=(1e18);
	for(int i=h;i<=h+10000;i++){
		ans=min(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}

