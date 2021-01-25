/*
* @author:  codancer
* @createTime:  time
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
pair<ll,ll> monster[200000];
int main(){
	int n,t;
	cin>>n>>t;
	rep(i,1,n){
		cin>>monster[i].first>>monster[i].second;
	}
	sort(monster+1,monster+n+1);
	int ti=1;//第几个周期
	ll nowmaxx=-1e9;//当前周期的最大值
	ll ans=0;
	rep(i,1,n){
		if(monster[i].first<=ti*t&&monster[i].first>(ti-1)*t){
			nowmaxx=max(nowmaxx,monster[i].second);
		}else{
			ans+=nowmaxx;
			nowmaxx=monster[i].second;
			++ti;
		}
	}
	ans+=nowmaxx;//最后一个周期
	cout<<ans<<endl;
	return 0;
}