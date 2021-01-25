#include<bits/stdc++.h>

using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	string xa="";
	string xb="";
	for(int i=1;i<=a;i++){
		xa+=char('0'+b);
	}
	for(int i=1;i<=b;i++){
		xb+=char('0'+a);
	}
	cout<<min(xa,xb)<<endl;
	return 0;
}

