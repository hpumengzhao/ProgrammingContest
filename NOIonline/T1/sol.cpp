#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+100;
ll n,L,m,a[N],p,tt,predis[N];
long long prim[400];
void init(){
	for(int i=1;i<=100;i++){
		prim[i]=i;
	}
	return ;
}
void init2(){
	for(int i=1;i<=100;i++){
		prim[i]=i;
	}
	return ;
}
int main(){
	freopen("endless.in","r",stdin) ;
	freopen("endless.in","w",stdin) ;
	cin>>n>>L>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;i++) {
		predis[i]=predis[i-1]+a[i];
	}
	cin>>p;
	while(p--){
		scanf("%lld",&tt);
		ll l=0;
		ll r=n+1;
		bool ok=0;
		for(int i=1;i<=32;i++){
			int mid=(l+r)/2;
			if(predis[mid]+L>tt*m){
				r=mid;
				ok=1;
			}else{
				l=mid;
			}
		}
		if(ok){
			cout<<r<<endl;
		}else{
			cout<<-1<<endl;
		}
	}
	return 0;
}
