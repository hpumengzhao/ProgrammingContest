/*
* @author:  codancer
* @createTime:  2020-03-22, 11:58:53
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
	scanf("%d",&T);
	int cnt=0;
	while(T--){
		int n,b;
		scanf("%d%d",&n,&b);
		vector<int> a(n);
		rep(i,0,n-1){
			scanf("%d",&a[i]);
		}
		sort(a.begin(),a.end());
		int ans=0;
		for(int v:a){
			if(b>=v){
				++ans;
				b-=v;
			}
		}
		printf("Case #%d: %d\n",++cnt,ans);
	}
	return 0;
}