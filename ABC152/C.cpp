#include<bits/stdc++.h>

using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	vector<int> minn(n+1,999999999);
	int ans=0;
	for(int i=1;i<=n;i++){
		minn[i]=min(minn[i-1],a[i]);
		if(a[i]==minn[i]) ans++;
	}
	cout<<ans<<endl;
	return 0;
}

