/*
* @author:  codancer
* @createTime:  2020-04-03, 13:33:53
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
void solve(){
	int n;
	string s;
	string t="Jyouhou";
	int ans=0;
	cin>>n>>s;
	int now=0;
	rep(i,0,n-1){
		if(s[i]==t[now]){
			if(now==6){
				++ans;
				now=-1;
			}
			now++;
		}
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}