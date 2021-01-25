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
int main(){
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	int tot=0;
	rep(i,1,n){
		cin>>a[i-1];
		tot+=a[i-1];
	}
	// cout<<tot<<endl;
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	int now=0;
	rep(i,0,n-1){
		if(a[i]*4*m<tot){
			break;
		}
		++now;
	}
	if(now>=m){
		puts("Yes");
	}else{
		puts("No");
	}
	return 0;
}