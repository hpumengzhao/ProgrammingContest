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
void solve(){
	int n,k;
	scanf("%d %d",&n,&k);
	vector<int> a(n+1);
	rep(i,1,n) scanf("%d",&a[i]);
	map<int,int> is;
	vector<int> pre(n+1,0);
	rep(i,2,n){
		pre[i]=pre[i-1];
		if(i<n&&a[i]>a[i-1]&&a[i]>a[i+1]){
			is[i]=1;
			++pre[i];
		}
	}
	int maxx=0;
	int ansl=1;
	for(int l=1;l+k-1<=n;l++){
		int num=pre[l+k-1]-pre[l-1];
		if(is[l]) --num;
		if(is[l+k-1]) --num;
		if(num>maxx){
			ansl=l;
			maxx=num;
		}
	}
	 printf("%d %d\n",maxx+1,ansl);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}