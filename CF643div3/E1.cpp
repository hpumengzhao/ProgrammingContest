/*
* @author:  codancer
* @createTime:  2020-04-13, 23:13:40
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
	vector<int> a(n+1);
	vector<int> id[201];
	rep(i,1,n){
		scanf("%d",&a[i]);
		id[a[i]].push_back(i);
	}
	int ans=0;
	rep(i,1,200){
		ans=max(ans,(int)id[i].size());
	}
	rep(i,1,200){
		rep(j,1,200){
			if(i!=j&&id[i].size()&&id[j].size()){
				int siz=(int)id[i].size();
				 if(id[i].size()+id[j].size()<=ans) continue;
				rep(x,1,siz/2){
					int outl=id[i][x-1];
					int outr=id[i][siz-x];
					//cout<<"out: "<<outl<<' '<<outr<<endl;
					int inl=lower_bound(id[j].begin(),id[j].end(),outl)-id[j].begin();
					int inr=upper_bound(id[j].begin(),id[j].end(),outr)-id[j].begin()-1;
					ans=max(ans,2*x+max(0,inr-inl+1));
					//cout<<i<<' '<<j<<' '<<x<<' '<<inl<<' '<<inr<<' '<<2*x+max(0,inr-inl+1)<<endl;
				}
			}
		}
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}