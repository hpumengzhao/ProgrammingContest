/*
* @author:  codancer
* @createTime:  2020-04-04, 20:12:19
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
	ll n,k;
	cin>>n>>k;
	cout<<min(n%k,abs(k-n%k))<<endl;
	return 0;
}