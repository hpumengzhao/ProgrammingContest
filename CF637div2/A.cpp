/*
* @author:  codancer
* @createTime:  2020-04-23, 22:10:30
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
long long solve(){
	ll n,a,b,c,d;
	cin>>n>>a>>b>>c>>d;
	if((a-b)*n<=c+d&&(a+b)*n>=c-d){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
}
int main(){
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}