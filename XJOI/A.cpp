/*
* @author:  codancer
* @createTime:  2020-04-05, 13:23:23
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define fep(i,a,b) for(int i=(a);i>=(b);i--)
typedef vector<int> VI;
typedef vector<ll> VII;
typedef pair<int,int> pii;
int main(){
	int n;
	cin>>n;
	cout<<n*(n+1)-1<<endl;
	if(n%2==0){
		for(int i=n;i>=1;i--) cout<<i<<' '<<1<<endl;
		for(int j=2;j<=n+1;j++){
			if(j%2==0){
				for(int i=1;i<=n;i++){
					if(i&1) cout<<i<<' '<<j<<endl;
					else cout<<i<<' '<<j+1<<endl;
				}
			}else{
				for(int i=n;i>=1;i--){
					if(i&1) cout<<i<<' '<<j<<endl;
					else cout<<i<<' '<<j-1<<endl;
				}
			}
		}
	}else{
		for(int j=1;j<=n+1;j++) cout<<1<<' '<<j<<endl;
		for(int i=2;i<=n;i++){
			if(i%2==0){
				for(int j=n+1;j>=1;j--){
					if(j%2==0){
						cout<<i<<' '<<j<<endl;
					}else{
						cout<<i+1<<' '<<j<<endl;
					}
				}
			}else{
				for(int j=1;j<=n+1;j++){
					if(j&1){
						cout<<i-1<<' '<<j<<endl;
					}else{
						cout<<i<<' '<<j<<endl;
					}
				}
			}
		}
	}
	return 0;
}