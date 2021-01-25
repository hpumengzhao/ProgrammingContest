/*
* @author:  codancer
* @createTime:  time
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
int fun(int x){
	int ans=0;
	while(x){
		if(x%10==1) ans++;
		x/=10;
	}
	return ans;
}
int main(){
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=fun(i);
	}
	cout<<ans<<endl;
	return 0;
}