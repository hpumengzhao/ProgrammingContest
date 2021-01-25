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
typedef vector<int> VI;
typedef pair<int,int> pii;
int count(int x){
	if(x==0) return 1;
	int ans=0;
	while(x){
		ans++;
		x/=10;
	}
	return ans;
}
int s[20],c[20];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>s[i]>>c[i];
	int ans=-1;
	for(int i=0;i<1000;i++){
		vector<int> now;
		if(count(i)==n){
			int p=i;
			if(p==0) now.pb(0);
			else{
				while(p){
					now.pb(p%10);
					p/=10;
				}
			}
			reverse(now.begin(),now.end());
			bool ok=1;
			for(int j=1;j<=m;j++){
				if(now[s[j]-1]!=c[j]) ok=0;
			}
			if(ok==1){
				cout<<i<<endl;
				return 0;
			}
		}
	}
	cout<<-1<<endl;
	return 0;
}

