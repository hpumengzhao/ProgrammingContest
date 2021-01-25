/*
* @author:  codancer
* @createTime:  2020-02-17, 09:39:06
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
#define pb push_back
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef pair<int,int> pii;
ll n,k,ans,l,r;
ll a[200010];
bool check(ll x){
	ll cnt=0;// the number that less than x
	for(int i=1;i<=n;i++){
		ll num=0;
		if(a[i]==0){
			if(x>0) cnt+=n;
		}else{
			if(a[i]>0){
				ll h=x/a[i];
				if(x%a[i]&&(x>0)){
					++h;
				}
				num=lower_bound(a+1,a+n+1,h)-a-1;
			}
			else{
				ll h=x/a[i];
				if(x%a[i]&&(x>0)){
					h--;
				}
				ll great=upper_bound(a+1,a+n+1,h)-a-1;
				num=n-great;
			}
			cnt+=num;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]*a[i]<x) --cnt;
	}
	cnt/=2;
	return cnt<k;
}

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	l=-1e18,r=1e18;
	ll ans;
	// cout<<check(-6)<<endl;
	while(l<=r){
		ll mid=l+r>>1;
		if(check(mid)){
			 l=mid+1;
			 ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}