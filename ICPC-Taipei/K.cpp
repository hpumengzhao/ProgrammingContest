/*
* @author:  codancer
* @createTime:  2020-04-01, 17:08:05
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
	int n;
	scanf("%d",&n);
	vector<int> a(n+1);
	priority_queue<int,vector<int>,greater<int>> q;
	rep(i,1,n){
		scanf("%d",&a[i]);
		q.push(a[i]);
	}
	int ans=0;
	while(q.size()>1){
		int x=q.top();q.pop();
		int y=q.top();q.pop();
		ans+=x+y;
		q.push(x+y);
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}