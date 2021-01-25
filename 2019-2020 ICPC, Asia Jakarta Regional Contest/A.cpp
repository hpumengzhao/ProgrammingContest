#include<bits/stdc++.h>
 
using namespace std;
int a[1000000];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) {
			cout<<n+1-a[i]<<' ';
	}
	cout<<endl;
	return 0;
}
