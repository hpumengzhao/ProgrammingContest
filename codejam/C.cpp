/*
* @author:  codancer
* @createTime:  2020-04-05, 08:30:24
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
#define pb push_back
#define fi first
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define fep(i,a,b) for(int i=(a);i>=(b);i--)
typedef vector<int> VI;
typedef vector<ll> VII;
typedef pair<int,int> pii;
struct ac{
	int s,e;
	int id;
};
bool cmp(ac a,ac b){
	return a.e<b.e;
}
void solve(){
	map<int,int> mps;
	int n;
	scanf("%d",&n);
	vector<ac> all(n);
	rep(i,0,n-1){
		scanf("%d %d",&all[i].s,&all[i].e);
		all[i].id=i;
	}
	sort(all.begin(),all.end(),cmp);
	int x=all[0].e;
	mps[all[0].id]=1;
	rep(i,1,n-1){
		if(all[i].s>=x){
			mps[all[i].id]=1;
			x=all[i].e;
		}
	}
	vector<ac> left;
	for(auto v:all){
		if(!mps[v.id]){
			left.pb(v);
		}
	}
	sort(left.begin(),left.end(),cmp);
	int m=(int)left.size();
	if(m){
		int ans=1;
		x=left[0].e;
		rep(i,1,m-1){
			if(left[i].s>=x){
				x=left[i].s;
				++ans;
			}
		}
		if(ans!=m){
			printf("IMPOSSIBLE\n");
		}else{
			for(int i=0;i<n;i++){
				if(mps[i]){
					printf("C");
				}else{
					printf("J");
				}
			}
			puts("");
		}
	}else{
		rep(i,1,n){
			printf("C");
		}
		puts("");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	rep(t,1,T){
		printf("Case #%d: ", t);
		solve();
	}
	return 0;
}