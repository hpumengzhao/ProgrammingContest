#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const ll INF=0x3f3f3f3f;
const ll maxn=1000000+10;
ll a[maxn];
pair<ll,ll> polls[maxn];
int main(){
	ll n;
	cin>>n;
	ll line=1;
	for(ll i=1;i<=2*n;i++){
		cin>>a[i];
	}
	polls[1]={a[1],0};
	for(ll i=2;i<=2*n;i++){
		if(line==1){
			polls[i]={a[i],polls[i-1].second+a[i]-polls[i-1].first};
		}else{
			polls[i]={a[i],polls[i-1].second-a[i]+polls[i-1].first};
		}
		line=-line;
	}
	polls[2*n+1]={polls[2*n].first+polls[2*n].second,0};
	ll x,y;
	cin>>x;
	line=1;
	for(ll i=2;i<=2*n+1;i++){
		if(polls[i-1].first<=x&&polls[i].first>=x){
			if(line==1){
				y=polls[i-1].second+x-polls[i-1].first;
			}else{
				y=polls[i-1].second-x+polls[i-1].first;
			}
		}
		line=-line;
	}
	long long ans=0;
//	cout<<x<<' '<<y<<endl;
	for(ll i=1;i<=2*n+1;i++){
		if(polls[i].first<x&&polls[i].second>y){
			//cout<<polls[i].first<<' '<<polls[i].second<<' '<<endl;
			long long up=x*(polls[i].second-y);
			long long down=((x-polls[i].first));
			ans=max(ans,up/down+(up%down?1:0)+y);
		}
		if(polls[i].first<x&&polls[i].second<=y){
			ll up=(x*polls[i].second-polls[i].first*y);
			ll down=x-polls[i].first;
			if(up*down<0) continue;	
			ans=max(ans,up/down+(up%down?1:0));
		}
	}
	cout<<ans<<endl;
	return 0;
}
