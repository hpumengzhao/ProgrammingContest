/*
* @author:  codancer
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
#define pb push_back
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define fep(i,a,b) for(int i=(a);i>=(b);i--)
typedef vector<int> VI;
typedef pair<int,int> pii;
void solve(){
	string s;
	cin>>s;
	string ans="";
	int n=(int)s.length();
	int left=0;
	rep(i,0,n-1){
		int now=s[i]-'0';
		if(left>=now){
			int x=left;
			rep(j,1,x-now){
				ans+=")";
				--left;
			}
		}else{
			int x=left;
			rep(j,1,now-x){
				ans+="(";
				++left;
			}
		}
		ans+=s[i];
	}
	rep(j,1,left) ans+=")";
	cout<<ans<<endl;
} 
int main(){
	int T;
	scanf("%d",&T);
	rep(t,1,T){
		printf("Case #%d: ",t);
		solve();
	}
	return 0;
}

