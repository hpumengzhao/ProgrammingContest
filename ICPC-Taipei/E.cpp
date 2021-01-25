/*
* @author:  codancer
* @createTime:  2020-04-01, 18:46:23
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
int solve(vector<int> a,int n){
	int ans=0;
	int curmax=0;
	int left=0;
	rep(i,1,n){
		curmax+=a[i];
		if(curmax<0){
			curmax=0;
			left=i;
		}
		cout<<i<<' '<<curmax<<endl;
		ans=max(ans,(i-left)*curmax);
	}
	return ans;
}
int main(){
	int n;
	cin>>n;
	vector<int> a(n+1);
	rep(i,1,n) cin>>a[i];
	cout<<solve(a,n)<<endl;
	return 0;
}