/*
* @author:  codancer
* @createTime:  2020-04-18, 20:06:53
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
ll all[3000][3000],pre[3000][3000];
int main(){
	int n,m,k,q;
	scanf("%d %d %d %d",&n,&m,&k,&q);
	rep(i,1,n){
		rep(j,1,m){
			all[i][j]=0;
		}
	}
	int x1,y1,x2,y2;
	rep(i,1,k){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		all[x1][y1]++;
		all[x1][y2+1]--;
		all[x2+1][y1]--;
		all[x2+1][y2+1]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			all[i][j]=all[i][j]+all[i-1][j]+all[i][j-1]-all[i-1][j-1];
		}
	}
	rep(i,1,n){
		rep(j,1,m){
			all[i][j]+=all[i-1][j]+all[i][j-1]-all[i-1][j-1];
		}
	}
	rep(i,1,q){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		printf("%lld\n", all[x2][y2]-all[x1-1][y2]-all[x2][y1-1]+all[x1-1][y1-1]);
	}
	return 0;
}