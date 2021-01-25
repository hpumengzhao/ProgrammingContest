/*
* @author:  codancer
* @createTime:  2020-04-04, 20:29:16
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
	ll n;
	cin>>n;
	if(n==2){
		cout<<1<<endl;
	}
	set<ll> ans;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			ll x=n;
			while(x%i==0){
				x/=i;
			}
			if(x%i==1){
				ans.insert(i);
			}
			if(i*i!=n){
				if(i%(n/i)==1){
					ans.insert(n/i);
				}
			}
		}else if(n%i==1){
			ans.insert(i);
		}
	}

	for(ll i=2;i*i<=(n-1);i++){
		if((n-1)%i==0){
			if(i*i==n-1){
				ans.insert(i);
			}else{
				if(n%i)ans.insert(i);
				if((n%((n-1)/i))) ans.insert((n-1)/i);
			}
		}
	}
	ans.insert(n-1);
	ans.insert(n);
	cout<<ans.size()<<endl;
	return 0;
}