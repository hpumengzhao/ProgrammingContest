/*
* @author:  codancer
* @createTime:  2020-04-05, 15:25:33
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
int n;
bool check(pair<int,int> a,pair<int,int> b){
	if(abs(a.first-b.first)==1&&abs(a.second-b.second)==1) return 1;
	if(a.first==1&&b.first==1&&b.second-a.second==1){
		return 1;
	}
	if(a.first==n&&a.first==n&&a.second-b.second==1){
		return 1;
	}
	if(a.second==1&&a.second==1&&b.first-a.first==-1){
		return 1;
	}
	if(a.second==n+1&&b.second==n+1&&b.first-a.first==1){
		return 1;
	}
	return 0;
}
int main(){
	vector<pair<int,int> > all;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n+1;j++){
			all.pb({i,j});
		}
	}
	do{
		bool ok=1;
		for(int i=1;i<n*(n+1);i++){
			if(!check(all[i-1],all[i])){
				ok=0;
				break;
			}
		}
		if(ok){
			for(auto v:all){
				cout<<v.first<<' '<<v.second<<endl;
			}
			return 0;
		}
	}while(next_permutation(all.begin(),all.end()));
	return 0;
}