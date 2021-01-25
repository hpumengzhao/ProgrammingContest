/*
* @author:  codancer
* @createTime:  time
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
	freopen("1.in","r",stdin);
	// freopen("1.out","w",stdout);
	ll x;
	VII a;
	while(cin>>x){
		a.pb(x);
	}
	cout<<a.size()<<endl;
	sort(a.begin(),a.end());
	int n=(int)a.size();
	cout<<a[0];
	for(int i=1;i<n;i++) cout<<","<<a[i];
		cout<<endl;
	return 0;
}