#include<bits/stdc++.h>

using namespace std;
int main(){
	long long h;
	cin>>h;
	long long dep=0;
	while(h){
		dep++;
		h>>=1;
	} 
	cout<<(1LL<<dep)-1<<endl;
	return 0;
}

