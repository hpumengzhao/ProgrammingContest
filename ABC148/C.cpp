#include<bits/stdc++.h>

using namespace std;
long long lcm(long long a,long long b){
	return a*b/__gcd(a,b);
}
int main(){
	long long a,b;
	cin>>a>>b;
	cout<<lcm(a,b)<<endl;
	return 0;
}

