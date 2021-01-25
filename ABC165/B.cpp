/*
* @author:  codancer
* @createTime:  2020-05-02, 20:13:17
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
	ll N,x=100;
	cin>>N;
	rep(i,1,10000000000){
		x=x+x/100;
		if(x>=N){
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}