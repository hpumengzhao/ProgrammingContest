/*
* @author:  codancer
* @createTime:  2020-02-22, 19:58:19
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
	int n,r;
	cin>>n>>r;
	if(n>=10){
		cout<<r<<endl;
	}else{
		cout<<r+100*(10-n)<<endl;
	}
	return 0;
}