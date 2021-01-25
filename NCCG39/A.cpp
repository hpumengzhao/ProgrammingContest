/*
* @author:  codancer
* @createTime:  2020-04-17, 18:57:45
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
	vector<ll> a(n);
	rep(i,0,n-1){
		scanf("%lld",&a[i]);
	}
	sort(a.begin(),a.end());
	ll maxx=1e18;
	rep(i,0,n-1){
		ll ans=0;
		if(a[i]<0){
			if(a[n-1]>=0){
				 ans=max(ans,a[n-1]);
			}
			int id=lower_bound(a.begin(),a.end(),0)-a.begin();
			--id;
			int len=id-i+1;
			int mid=(i+len/2);
			ans=max(ans,min(-a[mid],a[mid]-a[i]));
			if(mid>i) ans=max(ans,min(-a[mid-1],a[mid-1]-a[i]));
			if(mid+1<=id) ans=max(ans,min(-a[mid+1],a[mid+1]-a[i]));
			
			ans=max(ans,a[i]-a[0]);
		}else{
			if(a[0]<=0){
				 ans=max(ans,-a[0]);
			}
			int id=upper_bound(a.begin(),a.end(),0)-a.begin();
			int len=i-id+1;
			int mid=(id+len/2);
			ans=max(ans,min(a[mid],a[i]-a[mid]));
			if(mid>id) ans=max(ans,min(a[mid-1],a[i]-a[mid-1]));
			if(mid+1<=i) ans=max(ans,min(a[mid+1],a[i]-a[mid+1]));
			ans=max(ans,a[n-1]-a[i]);
		}
		maxx=min(maxx,ans);
	}
	printf("%lld\n",maxx);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}