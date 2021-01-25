/*
* @author:  codancer
* @createTime:  2020-04-13, 22:21:28
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
	while(T--){
		ll n;
		scanf("%lld",&n);
		printf("%lld\n",(n-1)/2);
	}
	return 0;
}