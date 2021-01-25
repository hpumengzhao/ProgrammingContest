#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e6+100;
const ll mod = 1e9+7;
ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int n;
int a[N],b[N];
bool check(int x){
	int curx=0,cury=0;
	for(int i=1;i<=n;i++){
		if(a[i]>x){
			if(!curx) curx=a[i];
			else{
				if(curx!=a[i]) return true;
				else curx=0;
			}
		}
		if(b[i]>x){
			if(!cury) cury=b[i];
			else{
				if(cury!=b[i]) return true;
				else cury=0;
			}
		}
	}
	return curx!=0 || cury!=0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	int l=0,r=1000000000+10;
	while(l<=r){
		int m=(l+r)/2;
		if(check(m)) l=m+1;
		else r=m-1;
	}
	printf("%d\n",l);
	return 0;
}
