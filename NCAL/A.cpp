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
int reve(int n){
	int ans=0;
	while(n){
		ans=ans*10+n%10;
		n/=10;
	}
	return ans;
}
int main(){
	int n;
	cin>>n;
	cout<<n+reve(n)<<endl;
	return 0;
}