/*
* @author:  codancer
* @createTime:  2020-04-15, 17:13:06
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
string maze[200];
int main(){
	int n,m;
	cin>>n>>m;
	rep(i,0,n-1) cin>>maze[i];
	int lx=m-1,rx=0;
	vector<int> all;
	rep(i,0,n-1){
		int x=0;
		bool ok=0;
		rep(j,0,m-1){
			if(maze[i][j]!='.'){
				x=j;
				ok=1;
				break;
			}
		}
		lx=min(lx,x);
		x=m-1;
		fep(j,m-1,0){
			if(maze[i][j]!='.'){
				x=j;
				break;
			}
		}
		rx=max(rx,x);
		all.pb((rx+lx)/2);
	}
	sort(all.begin(),all.end());
	int mid=all[n/2];
	rep(i,0,m-1){
		if(maze[n-1][i]!='.'){
			lx=i;
			break;
		}
	}
	fep(i,m-1,0){
		if(maze[n-1][i]!='.'){
			rx=i;
			break;
		}
	}
	if(mid<lx){
		cout<<"left"<<endl;
		return 0;
	}
	if(mid>rx){
		cout<<"right"<<endl;
		return 0;
	}
	cout<<"balanced"<<endl;
	return 0;
}