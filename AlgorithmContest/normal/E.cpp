/*
* @author:  codancer
* @createTime:  2020-04-04, 09:43:44
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
	int n,m;
	cin>>n>>m;
	vector<ll> a(n+1);
	priority_queue<ll,vector<ll>,greater<ll>> q;
	rep(i,1,n){
		cin>>a[i];
	}	
	if(n<m){
		cout<<0<<endl;
		return 0;
	}
	ll st=0;
	ll ans=0;
	rep(i,1,n){
		if(q.size()<m){
			q.push(st+a[i]);
		}else{
			st=q.top();//当前结束
			ans=st;
			while(!q.empty()&&q.top()==st) q.pop();
			q.push(st+a[i]);
		}
	}
	if(q.size()==m) cout<<q.top()<<endl;
	else{
		cout<<ans<<endl;
	}
	return 0;
}