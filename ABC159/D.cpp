/*
* @author:  codancer
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
#define pb push_back
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define fep(i,a,b) for(int i=(a);i>=(b);i--)
typedef vector<int> VI;
typedef pair<int,int> pii;
ll cnt[300000];
int main(){
	int n;
	cin>>n;
	vector<int> a(n+1);
	rep(i,1,n){
		 cin>>a[i];
		 ++cnt[a[i]];
	}
	long long ans=0;
	rep(i,1,200000){
		if(cnt[i]){
			ans+=cnt[i]*(cnt[i]-1)/2;
		}
	}
	rep(i,1,n){
		cout<<ans-(cnt[a[i]]-1)<<endl;
	}
	return 0;
}

