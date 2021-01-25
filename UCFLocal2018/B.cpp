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
	map<char,int> mps;
	for(auto c:s){
		mps[c]++;
	}
	int n=(int)s.length();
	int od=0;
	int eve=0;
	for(int i=0;i<26;i++){
		if(mps[i+'a']%2==0&&mps[i+'a']){
			++eve;
		}else if(mps[i+'a']%2==1&&mps[i+'a']){
			++od;
		}
	}
	// cout<<eve<<' '<<od<<endl;
	if(eve&&od){
		puts("2");
		return 0;
	}
	if(eve){
		puts("0");
		return 0;
	}
	puts("1");
	return 0;
}