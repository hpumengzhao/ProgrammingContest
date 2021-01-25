/*
* @author:  codancer
* @createTime:  2020-03-28, 20:47:29
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
priority_queue<ll> C;
priority_queue<ll,vector<ll>,greater<ll>> R,G;

int main(){
	ll x,y,a,b,c;
	cin>>x>>y>>a>>b>>c;

	ll t;
	rep(i,1,a){
		cin>>t;
		R.push(t);
	}
	rep(i,1,b){
		cin>>t;
		G.push(t);
	}
	rep(i,1,c){
		cin>>t;
		C.push(t);
	}

	while(R.size()>x){
		 R.pop();
	}
	while(G.size()>y){
		 G.pop();
	}

	while(!C.empty()&&C.top()>=min(R.top(),G.top())){
		ll aminn=R.top();
		ll bminn=G.top();
		if(aminn<=bminn){
			R.pop();
			R.push(C.top());
			C.pop();
			continue;
		}else{
			G.pop();
			G.push(C.top());
			C.pop();
		}
	}
	ll ans=0;
	while(!R.empty()){
		ans+=R.top();
		R.pop();
	}
	while(!G.empty()){
		ans+=G.top();
		G.pop();
	}
	cout<<ans<<endl;
	return 0;
}