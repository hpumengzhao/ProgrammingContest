/*
* @author:  codancer
* @createTime:  2020-04-12, 19:57:58
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
	int n;
	cin>>n;
	while(n){
		if(n%10==7){
			cout<<"Yes"<<endl;
			return 0;
		}
		n/=10;
	}
	cout<<"No"<<endl;
	return 0;
}