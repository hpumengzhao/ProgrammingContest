/*
* @author:  codancer
* @createTime:  time
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
vector<ll> sq;
void init(){
	for(ll i=2;i<=100000;i++){
		sq.pb(i*i);
	}
}
int main(){
	long long n;
	init();
	cin>>n;
	// for(int n=2;n<=10000;n++){
		int ans=-1;
		for(ll m=2;m<n;m++){
			ll now=m*n;
			bool ok=1;
			for(ll v:sq){
				if(now%v==0){
					ok=0;
					break;
				}
			}
			if(ok){
				ans=m;
				break;
			}
		}
		cout<<ans<<endl;
	return 0;
}