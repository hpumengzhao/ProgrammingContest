/*
* @author:  codancer
* @createTime:  2020-02-16, 20:00:57
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
	int a,b,c;
	cin>>a>>b>>c;
	set<int> st;
	st.insert(a);
	st.insert(b);
	st.insert(c);
	if(st.size()==2){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}