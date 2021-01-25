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
int a[32]={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
long long cal(long long x){
	long long l=1;
	long long r=3e9;
	long long mid;
	for(int i=1;i<=200;i++){
		mid=(l+r)/2;
		if(mid*mid<=x){
			l=mid;
		}
		else {
			r=mid;
		}
	}
	return l;
}
int main(){
	long long  a,b,c;
	cin>>a>>b>>c;
	if(a+b+cal(4*a*b)<c){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}