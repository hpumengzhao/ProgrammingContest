#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
struct node{
	int num;
	int id;
}s[200];
bool cmp(node a,node b){
	return a.num>=b.num;
}
int main(){
	int n;
	cin>>n;
	ll sum=0;
	for(int i=1;i<=n;i++){
		cin>>s[i].num;
		s[i].id=i;
		sum+=s[i].num;
	}
	sort(s+1,s+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(s[i].num*2>sum){
			cout<<"impossible"<<endl;return 0;
		}
	}
	for(int i=1;i<=n-1;i++) cout<<s[i].id<<' ';
	cout<<s[n].id<<endl;
	return 0;
}
