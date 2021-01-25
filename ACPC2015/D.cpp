/*
* @author:  codancer
* @createTime:  2020-03-18, 17:22:03
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef pair<int,int> pii;
long long lcm(long long a,long long b){
	return a/__gcd(a,b)*b;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		int a,b;
		cin>>a>>b;
		vector<long long> num(a+b+2);
		for(int i=1;i<=a+b+1;i++){
			cin>>num[i];
		}
		int n=a+b+1; 
		long long ans=num[1];
		rep(i,2,a+b+1){
			if(i<=a+1){
				ans&=num[i];
			}else{
				ans|=num[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
