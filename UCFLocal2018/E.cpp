/*
* @author:  codancer
* @createTime:  2020-03-25, 17:12:11
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
	int n;
	string s;
	cin>>n;
	set<string> a[26];
	map<int,ll> al;
	map<string,int> mps;
	rep(i,1,n){
		cin>>s;
		mps[s]++;
		al[s[0]-'A']++;
		a[s[0]-'A'].insert(s);
	}
	ll ans=0;
	for(int i=0;i<26;i++){
		for(string v:a[i]){
			ans+=(al[i]-mps[v])*mps[v];
		}
	}
	cout<<ans<<endl;
	return 0;
}
