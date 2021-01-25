/*
* @author:  codancer
* @createTime:  2020-04-23, 23:31:14
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
const int N = 2e5+100;
pair<int,int> a[N];
void solve(){
	int n;
	scanf("%d",&n);
	rep(i,1,n){
		 scanf("%d",&a[i].first);
		 a[i].second=i;
	}
	sort(a+1,a+n+1);
	if(n==1){
		cout<<"Yes"<<endl;
		return ;
	}
	vector<pair<int,int> > seg;
	int now=a[1].second;
	int L=a[1].second;
	int R=a[1].second;
	rep(i,2,n){
		if(a[i].second==a[i-1].second+1){
			++R;
		}else{
			seg.push_back({L,R});
			L=R=a[i].second;
		}
	}
	seg.push_back({L,R});
	if((int)seg.size()==1){
		cout<<"Yes"<<endl;
		return ;
	}else{
		int siz=(int)seg.size();
		rep(i,1,siz-1){
			if((seg[i].second+1)!=seg[i-1].first){
				cout<<"No"<<endl;
				return ;
			}
		}
		cout<<"Yes"<<endl;
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}