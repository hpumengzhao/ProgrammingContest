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
const int MAXN = 100010;
int n,a[MAXN],pos[MAXN],dp[MAXN];

int main() {
	int n;
	cin>>n;
	rep(i,0,n-1){
		 cin>>a[i];
		 a[i]--;
		 pos[a[i]]=i;
	}
	int maxx=0;
	rep(i,0,n-1){
		if(a[i]==0) dp[i]=1;
		else if(pos[a[i]-1]<i){
			dp[i]=dp[pos[a[i]-1]]+1;
		}else{
			dp[i]=1;
		}
		maxx=max(maxx,dp[i]);
	}
	cout<<n-maxx<<endl;
    return 0;
}