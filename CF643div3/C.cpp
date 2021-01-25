/*
* @author:  codancer
* @createTime:  2020-04-13, 22:56:41
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
	scanf("%d",&n);
	vector<int> a(n+1);
	map<int,int> mps;
	set<int> st;
	rep(i,1,n){
		scanf("%d",&a[i]);
		++mps[a[i]];
		st.insert(a[i]);
	}
	int ans=0;
	int SZ=(int)st.size();
	for(int v:st){
		ans=max(ans,min(mps[v],SZ-1));
		ans=max(ans,min(mps[v]-1,SZ));
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}