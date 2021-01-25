/*
* @author:  codancer
* @createTime:  2020-04-12, 20:03:49
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
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(i%3==0||i%5==0) continue;
		ans+=i;
	}
	cout<<ans<<endl;
	return 0;
}