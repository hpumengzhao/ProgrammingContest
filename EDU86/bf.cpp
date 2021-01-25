/*
* @author:  codancer
* @createTime:  2020-04-27, 00:05:49
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
	for(int i=1;i<=9;i++){
		if((i%4)%6!=(i%6)%4){
			cout<<i<<endl;
		}
	}
	return 0;
}