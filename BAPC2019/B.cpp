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
	if(n&1){
		cout<<"Bob"<<endl;
	}else{
		cout<<"Alice"<<endl;
		cout<<n/2<<endl;
	}
	return 0;
}