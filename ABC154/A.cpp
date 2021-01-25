/*
* @author:  codancer
* @createTime:  2020-02-09, 20:01:05
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
	string S,T;
	int a,b;
	string U;
	cin>>S>>T>>a>>b>>U;
	if(S==U) a--;
	else b--;
	cout<<a<<' '<<b<<endl;
	return 0;
}