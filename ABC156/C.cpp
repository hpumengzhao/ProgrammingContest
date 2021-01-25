/*
* @author:  codancer
* @createTime:  2020-02-22, 20:05:28
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
	vector<int> x(n+1);
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	int ans=1e9;
	for(int i=1;i<=100;i++){
		int now=0;
		for(int j=1;j<=n;j++){
			now+=(x[j]-i)*(x[j]-i);
		}
		ans=min(ans,now);
	}
	cout<<ans<<endl;
	return 0;
}