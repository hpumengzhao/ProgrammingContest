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
	string s;
	cin>>s;
	string ans="";
	int l=s.length();
	rep(i,0,l-1){
		string now="";
		rep(j,i,l-1){
			now+=s[j];
			ans=max(ans,now);
		}
	}
	cout<<ans<<endl;
	return 0;
}