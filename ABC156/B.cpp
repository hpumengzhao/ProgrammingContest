/*
* @author:  codancer
* @createTime:  2020-02-22, 20:03:29
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
#define pb push_back
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef pair<int,int> pii;
int main(){
	int n,k;
	cin>>n>>k;
	int ans=0;
	while(n){
		ans++;
		n/=k;
	}
	cout<<ans<<endl;
	return 0;
}