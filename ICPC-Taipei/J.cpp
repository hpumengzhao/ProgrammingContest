/*
* @author:  codancer
* @createTime:  2020-04-01, 18:27:35
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
char maze[20][600];
bitset<501> a[22];
void solve(){
	int n,m;
	cin>>n>>m;
	rep(i,0,m-1) a[i].reset();
	rep(i,0,m-1){
		rep(j,0,n-1){
			cin>>maze[i][j];
			if(maze[i][j]=='1'){
				a[i].set(j);
			}
		}
	}
	int ans=10000;
	rep(i,0,(1<<m)-1){
		vector<int> selected;
		rep(j,0,m){
			if((i>>j)&1){
				selected.pb(j);
			}
		}
		bitset<501> now;
		now.reset();
		for(int v:selected){
			now|=a[v];
		}
		if(now.count()==n){
			ans=min(ans,(int)selected.size());
		}
	}
	if(ans==10000) ans=-1;
	printf("%d\n", ans);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}