#include<bits/stdc++.h>

using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=1;
	int len=0;
	for(int i=1;i<=n;i++){
		if(a[i]==cnt){
			++len;
			++cnt;
		}
	}
	if(len==0){
		cout<<-1<<endl;
	}else{
		cout<<n-len<<endl;
	}
	return 0;
}

