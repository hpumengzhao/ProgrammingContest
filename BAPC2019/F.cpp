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
int main(){
	int k;
	cin>>k;
	VI ans;
	for(int i=1;i<=k;i++){
		int n;
		cin>>n;
		vector<int> a(n+1);
		vector<int> maxx(n+2);
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		maxx[n+1]=0;
		for(int j=n;j>=1;j--){
			maxx[j]=max(maxx[j+1],a[j]);
		}
		set<int> st;
		st.insert(a[1]);
		bool ok=0;
		for(int j=2;j<=n-1;j++){
			auto it=st.upper_bound(a[j]);
			if(it!=st.end()){
				if(*it<maxx[j+1]){
					ok=1;
					break;
				}
			}
			st.insert(a[j]);
		}
		if(ok){
			ans.pb(i);
		}
	}
	cout<<ans.size()<<endl;
	for(int v:ans){
		cout<<v<<endl;
	}
	return 0;
}