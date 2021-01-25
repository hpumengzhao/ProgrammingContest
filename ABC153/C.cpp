#include<bits/stdc++.h>

using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	vector<long long> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	if(k>=n){
		cout<<0<<endl;
		return 0;
	}
	long long ans=0;
	for(int i=1;i<=n-k;i++) ans+=a[i];
	cout<<ans<<endl;
	return 0;
}

