/*
* @author:  codancer
* @createTime:  2020-04-25, 19:48:31
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
	cin>>n>>m;
	priority_queue<ll, vector<ll>, greater<ll> > q;
	ll x;
	rep(i,1,n){
		cin>>x;
		q.push(x);
	}
	rep(i,1,m){
		ll x=q.top(); q.pop();
		if(!q.empty()){
			ll y=q.top();
			q.pop();
			x+=y;
			q.push(x);
		}
	}
	cout<<q.top()<<endl;
	return 0;
}