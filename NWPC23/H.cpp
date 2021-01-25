/*
* @author:  codancer
* @createTime:  2020-03-21, 21:17:41
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
int main(){
	int T;
	cin>>T;
	while(T--){
		int m;
		cin>>m;
		int cnt[100]={0};
		int cnt2[100]={0};
		vector<pair<int,int> > a(m);
		vector<int> ans(m,0);
		rep(i,0,m-1){
			cin>>a[i].first;
			a[i].second=i;
		}
		sort(a.begin(),a.end());
		reverse(a.begin(),a.end());
		long long now=(1LL<<30);
		for(auto v:a){
			if(now>=(1LL<<(v.first))){
				now-=(1LL<<(v.first));
				ans[v.second]=1;
			}
		}
		if(now){
			cout<<"impossible"<<endl;
			continue;
		}
		for(int v:ans) cout<<v;
			cout<<endl;
	}
	return 0;
}