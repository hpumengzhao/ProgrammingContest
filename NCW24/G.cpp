/*
* @author:  codancer
* @createTime:  2020-04-18, 19:02:20
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
	ll n,m;
	scanf("%lld %lld",&n,&m);
	vector<ll> a(n);
	rep(i,0,n-1){
		scanf("%lld",&a[i]);
	}
	int ans=0;
	sort(a.begin(),a.end());
	for(int i=0;i<n;i++){
		if(m>=a[i]){
			++ans;
			m-=a[i];
		}
	}
	printf("%d\n",ans );
	return 0;
}