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
int main(){
	int n;
	cin>>n;
	vector<int> a(n+1);
	rep(i,1,n){
		cin>>a[i];
	}
	rep(i,1,n){
		rep(j,1,n){
			rep(k,1,n){
				if(i!=j&&i!=k&&j!=k){
					int ans=(a[i]-a[j])/a[k];
					if(ans*a[k]!=a[i]-a[j]){
						puts("no");
						return 0;
					}
				}
			}
		}
	}
	puts("yes");
	return 0;
}