#include<bits/stdc++.h>

using namespace std;
void print(__int128 x){
	if(x==0){
		puts("0");
		return ;
	}
	vector<int> ans;
	while(x){
		ans.push_back(x%10);
		x/=10;
	}
	reverse(ans.begin(),ans.end());
	for(int v:ans) printf("%d",v);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		long long a[5];
		__int128 ans=0;
		for(int i=1;i<=4;i++){
			scanf("%lld",&a[i]);
			ans+=a[i];
		}
		print(ans);
	}
	return 0;
}
