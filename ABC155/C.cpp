/*
* @author:  codancer
* @createTime:  2020-02-16, 20:05:58
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
	vector<string> a(n+1);
	map<string,int> mmp;
	int maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mmp[a[i]]++;
		maxx=max(maxx,mmp[a[i]]);
	}
	set<string> all;
	for(auto v:mmp){
		if(mmp[v.first]==maxx) all.insert(v.first);
	}
	for(string v:all) cout<<v<<endl;
	return 0;
}