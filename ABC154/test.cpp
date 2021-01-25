/*
* @author:  codancer
* @createTime:  2020-02-09, 20:49:25
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
int cal(int n){
	int ans=0;
	while(n){
		ans+=(n%10!=0);
		n/=10;
	}
	return ans;
}
int main(){
	int ans=0;
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		if(cal(i)==k) ans++;
	}
	cout<<ans<<endl;
	return 0;
}