/*
* @author:  codancer
* @createTime:  2020-04-24, 00:27:50
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
string lights[20]={"1110111","0010010","1011101","1011011","0111010","1101011","1101111","1010010","1111111","1111011"};
string s[20000];
int lastcost;
bool dp[2002][20000];//boolean cost j after approach i
int cost(int a,int b){// the cost of s[a]->lights[b]
	int ans=0;
	for(int j=0;j<7;j++){
		if(s[a][j]>lights[b][j]){
			return -1;
		}
		ans+=lights[b][j]-s[a][j];
	}
	return ans;
}
int main(){
	int n,k;
	cin>>n>>k;
	rep(i,1,n) cin>>s[i];
	dp[n+1][0]=1;
	lastcost=0;
	fep(i,n,1){
		fep(j,lastcost,0){
			if(dp[i+1][j]==0) continue;
			rep(k,0,9){
				int costs=cost(i,k);
				if(costs!=-1) dp[i][j+costs]|=dp[i+1][j];
				lastcost=max(lastcost,j+costs);
			}
		}
	}
	vector<int> ans;
	bool ok=1;
	rep(i,1,n){
		bool found=false;
		fep(j,9,0){
			int costs=cost(i,j);
			if(costs!=-1&&costs<=k){
				if(dp[i+1][k-costs]){
					ans.pb(j);
					k-=costs;
					found=true;
					break;
				}
			}
		}
		if(found==false){
			ok=0;
			break;
		}
	}
	if(ok){
		for(int v:ans) cout<<v;
			cout<<endl;
	}else{
		puts("-1");
	}
	return 0;
}