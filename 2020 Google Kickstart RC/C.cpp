/*
* @author:  codancer
* @createTime:  2020-05-19, 21:58:24
*/
#pragma GCC optimize(3)
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
int per[4000],a[100002];
int cnt=0;
void init(){
	for(int i=0;i*i<=10000000;i++){
		per[++cnt]=i*i;
	}
}
void solve(){
	int n;
	scanf("%d",&n);
	int s=0;
	int sum=0;
	int mxx=-200;
	rep(i,1,n) scanf("%d",&a[i]),mxx=max(mxx,a[i]),sum+=abs(a[i]);
	vector<int> mps(2*sum+1);
	long long ans=0;
	mps[sum]=1;
	rep(i,1,n){
		s+=a[i];
		rep(j,1,cnt){
			if(per[j]>s+sum) break;
			ans+=mps[s+sum-per[j]];
		}
		mps[s+sum]++;
	}
	printf("%lld\n", ans);
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	rep(tt,1,T){
		printf("Case #%d: ",tt);
		solve();
	}
	return 0;
}
