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
bool vis[10];
int main(){
	int n;
	cin>>n;
	vector<int> a(n+1);
	rep(i,1,n) cin>>a[i],vis[a[i]]=1;
	int kk;
	cin>>kk;
	vector<int> ok;
	rep(i,0,999){
		VI tmp;
		int x=i;
		if(x==0){
			tmp.pb(x);
		}
		while(x){
			tmp.pb(x%10);
			x/=10;
		}
		bool jud=1;
		for(int v:tmp){
			if(vis[v]) jud=0;
		}
		if(jud){
			ok.pb(i);
		}
	}
	int ans=100000;
	for(int v:ok){
		ans=min(ans,abs(v-kk));
	}
	cout<<ans<<endl;
	return 0;
}