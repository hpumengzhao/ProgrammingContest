/*
* @author:  codancer
* @createTime:  2020-04-12, 20:10:44
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
const int N = 5000;
ll R[N],G[N],B[N];
char s[N];
int main(){
	int n;
	scanf("%d",&n);
	scanf("%s",s+1);
	rep(i,1,n){
		R[i]=R[i-1];
		G[i]=G[i-1];
		B[i]=B[i-1];
		if(s[i]=='R') R[i]++;
		if(s[i]=='G') G[i]++;
		if(s[i]=='B') B[i]++;
	}
	ll ans=0;
	rep(i,2,n-1){
		if(s[i]=='R'){
			ans+=G[i-1]*(B[n]-B[i]);
			ans+=B[i-1]*(G[n]-G[i]);
			for(int steps=1;i-steps>=1&&i+steps<=n;steps++){
				if(s[i-steps]=='G'&&s[i+steps]=='B') --ans;
				if(s[i-steps]=='B'&&s[i+steps]=='G') --ans;
			}
		}
		if(s[i]=='G'){
			ans+=R[i-1]*(B[n]-B[i]);
			ans+=B[i-1]*(R[n]-R[i]);
			for(int steps=1;i-steps>=1&&i+steps<=n;steps++){
				if(s[i-steps]=='R'&&s[i+steps]=='B') --ans;
				if(s[i-steps]=='B'&&s[i+steps]=='R') --ans;
			}
		}
		if(s[i]=='B'){
			ans+=G[i-1]*(R[n]-R[i]);
			ans+=R[i-1]*(G[n]-G[i]);
			for(int steps=1;i-steps>=1&&i+steps<=n;steps++){
				if(s[i-steps]=='G'&&s[i+steps]=='R') --ans;
				if(s[i-steps]=='R'&&s[i+steps]=='G') --ans;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}