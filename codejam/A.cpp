/*
* @author:  codancer
* @createTime:  2020-04-04, 18:58:44
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
	vector<vector<int> > maze(n+1,vector<int>(n+1));
	rep(i,1,n){
		rep(j,1,n){
			scanf("%d",&maze[i][j]);
		}
	}
	int k=0;
	rep(i,1,n){
		k+=maze[i][i];
	}
	int r=0;
	rep(i,1,n){
		set<int> st;
		rep(j,1,n){
			st.insert(maze[i][j]);
		}
		if(st.size()<n) ++r;
	}
	int c=0;
	rep(j,1,n){
		set<int> st;
		rep(i,1,n){
			st.insert(maze[i][j]);
		}
		if(st.size()<n) ++c;
	}
	printf("%d %d %d\n",k,r,c);
}
int main(){
	int T;
	cin>>T;
	rep(t,1,T){
		printf("Case #%d: ",t);
		solve();
	}
	return 0;
}