/*
* @author:  codancer
* @createTime:  2020-04-14, 00:05:32
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
void change(char &c){
	if(c=='9') c='1';
	else c=c+1;
}
void solve(){
	string s[10];
	rep(i,0,8){
		cin>>s[i];
	}
	change(s[0][0]);
	change(s[1][3]);
	change(s[2][6]);
	change(s[3][1]);
	change(s[4][4]);
	change(s[5][7]);
	change(s[6][2]);
	change(s[7][5]);
	change(s[8][8]);
	rep(i,0,8){
		cout<<s[i]<<endl;
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}