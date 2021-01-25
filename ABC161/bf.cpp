#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define read(x) scanf("%d",&x)
typedef long long ll;
typedef double dl;
using namespace std;

const int N=2e5+7;
const int M=1e9+7;
const int INF=0x3f3f3f3f;

ll n,m;

void solve(){
	cin>>n;
	int cnt=0;
	if (n!=1) cnt++;
	if (n>2) cnt++;
	for(ll i=2;i*i<=n;i++){
		if (n%i!=0){
			if (n%i==1){
				cnt++;
//				cout<<i<<endl;
				if (n % ((n-1)/i) != 0&&(n-1)/i!=i){
					cnt++; 
					//cout<<(n-1)/i<<endl;
				}
			}
		}
		else{
			ll tmp=n;
			while (tmp!=0&&tmp%i==0) tmp/=i;
			if (tmp%i==1) cnt++;//cout<<i<<endl;
			if (i%(n/i)==1&&n/i!=i) cnt++;//cout<<n/i<<endl;
		}
	}
	cout<<cnt;
}

int main(){
//	ios::sync_with_stdio(0);
//  cin.tie(0),cout.tie(0);
//	int T;read(T);
//	for(int i=1;i<=T;i++)
		solve();
}
