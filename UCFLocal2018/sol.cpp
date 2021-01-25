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
	string a,b;
	double k;
	cin>>a>>b;
	int n=(int)a.length();
	int same=0;
	rep(i,0,n-1){
		if(a[i]==b[i]){
			++same;
		}
	}
	double rat=same*1.0/n;
	if(rat>=k){
		puts("yes");
	}else{
		puts("no");
	}
	return 0;
}