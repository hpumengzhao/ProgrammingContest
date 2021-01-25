/*
* @author:  codancer
* @createTime:  2020-04-01, 16:59:22
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
	getline(cin,s);
	int l=(int)s.length();
	vector<string> all;
	string now;
	rep(i,0,l-1){
		if(s[i]!=' '){
			now+=s[i];
		}else{
			all.pb(now);
			now="";
		}
	}
	all.pb(now);
	vector<string> ans;
	for(string v:all){
		if(v=="bubble"||v=="tapioka"){
			continue;
		}
		ans.pb(v);
	}
	if(ans.size()==0){
		puts("nothing");
	}else{
		for(int i=0;i<(int)ans.size();i++){
			if(i==0) cout<<ans[i];
			else cout<<' '<<ans[i];
		}
		cout<<endl;
	}
	return 0;
}