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
char maze[20][3000];
int c[3000][20];//第j列的前i行的前缀和
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	rep(i,1,n){
		rep(j,1,m){
			cin>>maze[i][j];
		}
	}
	rep(j,1,m){
		c[j][0]=0;
		rep(i,1,n){
			c[j][i]=c[j][i-1]+(maze[i][j]-'0');
		}
	}
	
	int ans=1e9;
	for(int i=0;i<(1<<(n-1));i++){
		vector<int> lc;
		int now=0;
		for(int j=0;j<(n-1);j++){
			if((i>>j)&1){
				lc.pb(j+1);
			}
		}
		int siz=(int)lc.size();
		now+=siz;
		
		vector<pair<int,int> > sq;//第i块的区间
				
		if(siz==0){//不切 
			sq.pb({1,n});
		}else{
			sq.pb({1,lc[0]});
			rep(j,1,siz-1){
				sq.pb({lc[j-1]+1,lc[j]});
			} 
			sq.pb({lc[siz-1]+1,n});
		}
		
		//先检验横着划分的可行性 
		bool flag=1;
		rep(j,1,m){
			rep(d,0,siz){
				int up=sq[d].first;
				int down=sq[d].second;
				if(c[j][down]-c[j][up-1]>k){
					flag=0;
					break;
				}
			}
		}
		if(flag==0) continue;
		
//		cout<<sq.size()<<' '<<now<<endl;
//		for(auto v:sq){
//			cout<<v.first<<"---"<<v.second<<endl;
//		}
		
		vector<int> tmp(siz+1,0);//第i块当前白色的数量 
		rep(j,1,m){
			bool ok=1;
			rep(d,0,siz){
				int up=sq[d].first;
				int down=sq[d].second;
				if(tmp[d]+c[j][down]-c[j][up-1]>k){
					ok=0;
					break;
				}
				tmp[d]+=(c[j][down]-c[j][up-1]);
			}
			if(ok==0){
				++now;
				rep(d,0,siz){
					int up=sq[d].first;
					int down=sq[d].second;
					tmp[d]=c[j][down]-c[j][up-1];
				}
			}
		}
		ans=min(ans,now);
	}
	
	cout<<ans<<endl;
	return 0;
}

