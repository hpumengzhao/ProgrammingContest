#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const int INF=0x3f3f3f3f;
const int maxn=1000000+10;
bool check(string s){
	string t=s;
	reverse(s.begin(),s.end());
	return s==t;
}
int main()
{
	int k;
	string s;
	cin>>s>>k;
	k%=2;
	if(k==0){
		if(check(s)){
			cout<<"YES"<<endl;
			return 0;
		}
		cout<<"NO"<<endl;
		return 0;
	}
	else{
		s=s+s;
		if(check(s)){
			cout<<"YES"<<endl;
			return 0;
		}
		cout<<"NO"<<endl;
		return 0;
	}
	return 0;
}
