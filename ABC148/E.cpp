#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll cal(ll n){
	ll ans=0;
	while(n){
		ans+=n/5;
		n=n/5;
	}
	return ans;
}
int main(){
	ll n;
	cin>>n;
	if(n&1){
		cout<<0<<endl;
		return 0;
	}
	n>>=1;
	cout<<cal(n)<<endl;
	return 0;
}

