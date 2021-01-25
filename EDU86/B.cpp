/*
* @author:  codancer
* @createTime:  2020-04-26, 22:58:35
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
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		int n=(int)s.length();
		// if(n<=2){
		// 	cout<<s<<endl;
		// }else{
			int x=0;
			int y=0;
			for(char c:s){
				if(c=='1') x++;
				else y++;
			}
			if(x==0||y==0){
				cout<<s<<endl;
				continue;
			}
			for(int i=0;i<n;i++){
				cout<<s[i];
				if(s[i]=='1'){
					if(i+1<n&&s[i+1]!='0') cout<<'0';
				}else{
					if(i+1<n&&s[i+1]!='1') cout<<'1';
				}
			}
			cout<<endl;
		}
	// }
	return 0;
}