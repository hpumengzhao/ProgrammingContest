/*
* @author:  codancer
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
#define pb push_back
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define fep(i,a,b) for(int i=(a);i>=(b);i--)
typedef vector<int> VI;
typedef pair<int,int> pii;
int main(){
	ll n,m;
	cin>>n>>m;
	cout<<(n*(n-1)/2+m*(m-1)/2)<<endl;
	return 0;
}

