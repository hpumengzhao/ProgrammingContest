/*
* @author:  codancer
* @createTime:  2020-02-24, 11:36:18
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
	int n;
	cin>>n;
	vector<int> ans;
	while(n){
		ans.pb(n%2);
		n/=2;
	}
	reverse(ans.begin(),ans.end());
	for(int v:ans)cout<<v;
		cout<<endl;
	return 0;
}