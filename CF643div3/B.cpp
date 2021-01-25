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
void solve(){
	int n,a,b;
	scanf("%d %d %d",&n,&a,&b);
	string ans="";
	int num[27]={0};
	int now=1;
	rep(i,1,b){
		ans+='a'+i-1;
		num[i]++;
	}
	rep(i,b+1,a){
		ans+='a'+b-1;
		num[b]++;
	}
	rep(i,a+1,n){
		num[ans[i-a-1]-'a'+1]--;
		int cnt=0;
		rep(j,1,26){
			if(num[j]){
				++cnt;
			}
		}
		if(cnt==b){
			rep(j,1,26){
				if(num[j]){
					ans+='a'+j-1;
					++num[j];
					break;
				}
			}
		}else{
			rep(j,1,26){
				if(num[j]==0){
					ans+='a'+j-1;
					++num[j];
					break;
				}
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}