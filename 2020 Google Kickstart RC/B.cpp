/*
* @author:  codancer
* @createTime:  2020-05-19, 21:15:11
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
const int N = 200;
vector<int> G[N];
bool adj[N][N];
char s[N][N];
int ind[N];
void solve(){
	rep(i,1,100) G[i].clear();
	memset(ind,0,sizeof(ind));
	memset(adj,0,sizeof(adj));
	int n,m;
	cin>>n>>m;
	set<char> sts;
	rep(i,1,n){
		rep(j,1,m){
			cin>>s[i][j];
			sts.insert(s[i][j]);
		}
	}
	rep(i,1,n-1){
		rep(j,1,m){
			adj[s[i+1][j]-'A'+1][s[i][j]-'A'+1]=1;
		}
	}
	rep(i,1,26){
		rep(j,1,26){
			if(i!=j&&adj[i][j]==1){
				G[i].pb(j);
				ind[j]++;
			}
		}
	}
	string ans="";
	queue<int> q;
	rep(i,1,26){
		if(ind[i]==0&&sts.find(char('A'+i-1))!=sts.end()){
			q.push(i);
		}
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		ans+=char('A'+u-1);
		for(int v:G[u]){
			ind[v]--;
			if(ind[v]==0) q.push(v);
		}
	}
	if((int)sts.size()!=(int)ans.length()){
		cout<<"-1"<<'\n';
		return ;
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	cin>>T;
	rep(tt,1,T){
		printf("Case #%d: ",tt);
		solve();
	}
	return 0;
}
