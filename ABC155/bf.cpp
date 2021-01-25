/*
* @author:  codancer
* @createTime:  2020-02-16, 21:02:55
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
	cout<<(8/-3)<<endl;
	int n,k;
	cin>>n>>k;
	vector<long long> ans;
	vector<long long> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans.push_back(a[i]*a[j]);
		}
	}
	sort(ans.begin(),ans.end());
	cout<<ans[k-1]<<endl;
	return 0;
}