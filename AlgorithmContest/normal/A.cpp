/*
* @author:  codancer
* @createTime:  2020-04-04, 08:50:58
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define fep(i,a,b) for(int i=(a);i>=(b);i--)
typedef vector<int> VI;
typedef vector<ll> VII;
typedef pair<int,int> pii;
int main(){
	ll n,X;
	cin>>n>>X;
	string base;
	cin>>base;
	for(int i=1;i<=n;i++){
		string av;
		cin>>av;
		ll now=0;
		int l=(int)av.length();
		for(int j=2;j<l;j++){
			now=now*10+(av[j]-'0');
		}
		now^=X;
		string ans="BV";
		string ans2="";
		while(now){
			ans2+=base[now%62];
			now/=62;
		}
		reverse(ans2.begin(),ans2.end());
		ans+=ans2;
		cout<<ans<<endl;
	}
	return 0;
}