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
	int n,k;
	scanf("%d %d",&n,&k);
	vector<int> a(n+1);
	rep(i,1,n) scanf("%d",&a[i]);
	int ans=0;
	int now=k;
	rep(i,1,n){
		if(a[i]==k){
			int len=1;
			while(i<n&&a[i+1]==a[i]-1){
				++i;
				++len;
			}
			if(len==k) ++ans;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	int T;
	cin>>T;
	rep(tt,1,T){
		printf("Case #%d: ", tt);
		solve();
	}
	return 0;
}
