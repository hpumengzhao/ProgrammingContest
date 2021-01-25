#include<bits/stdc++.h>

using namespace std;
int main(){
	int h;
	int n;
	cin>>h>>n;
	vector<int> a(n+1);
	int s=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
	}
	cout<<(s>=h?"Yes":"No")<<endl;
	return 0;
}

