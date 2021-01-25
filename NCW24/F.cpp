/*
* @author:  codancer
* @createTime:  2020-04-18, 19:12:03
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
bool win(string a,string b){
	if(a=="elephant"&&b=="tiger"){
		return 1;
	}
	if(a=="tiger"&&b=="cat"){
		return 1;
	}
	if(a=="cat"&&b=="mouse"){
		return 1;
	}
	if(a=="mouse"&&b=="elephant"){
		return 1;
	}
	return 0;
}
int main(){
	string s;
	getline(cin,s);
	int n=(int)s.length();
	string a="";
	string b="";
	int blankid;
	for(int i=0;i<n;i++){
		if(s[i]!=' ') a+=s[i];
		else{
			blankid=i;
			break;
		}
	}
	for(int i=blankid+1;i<n;i++){
		b+=s[i];
	}
	if(win(b,a)){
		puts("tiangou txdy");
	}else{
		puts("tiangou yiwusuoyou");
	}
	return 0;
}