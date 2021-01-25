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
	int n;
	cin>>n;
	set<int> st;
	VI a(n+1);
	for(int i=1;i<=n;i++){
		 cin>>a[i];
		 st.insert(a[i]);
	}
	cout<<(st.size()==n?"YES":"NO")<<endl;
	return 0;
}