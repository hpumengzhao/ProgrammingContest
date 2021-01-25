/*
* @author:  codancer
* @createTime:  2020-05-02, 20:21:33
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
int N,M,Q;
int a[100],b[100],c[100],d[100];
int ans=0;
int all[100];
void dfs(int x,int id){
	if(id==N+1){
		int now=0;
		for(int i=1;i<=Q;i++){
			if(all[b[i]]-all[a[i]]==c[i]) now+=d[i];
		}
		ans=max(ans,now);
		return ;
	}
	all[id]=x;
	for(int i=x;i<=M;i++){
		dfs(i,id+1);
	}
	all[id]=0;
}
int main(){
	cin>>N>>M>>Q;
	rep(i,1,Q){
		cin>>a[i]>>b[i]>>c[i]>>d[i];
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}