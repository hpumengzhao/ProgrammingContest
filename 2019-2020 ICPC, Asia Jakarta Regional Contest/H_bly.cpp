#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int maxn = 4e5+100;
struct node{
	ll l,w;
}a[maxn];
struct point{
	ll l,size;
	ll twin;
}e[maxn];
bool cmp(point i,point j){
	if(i.l==j.l) return i.size>j.size;
	return i.l>j.l;
}
map<ll,ll>mp;
int main(){
	int n;
	scanf("%d",&n);
	ll ans=0;
	for(int i=1;i<=n;i++){
		scanf("%lld %lld",&a[i].l,&a[i].w);
		if(a[i].l>a[i].w)swap(a[i].l,a[i].w);
		e[i*2-1].l=a[i].l;e[i*2-1].size=0;e[i*2-1].twin=a[i].w;
		e[i*2].l=a[i].w;e[i*2].size=1;e[i*2].twin=a[i].l;
		ans=max(ans,a[i].l*a[i].w);
	}
//	printf("%lf\n",ans);
	sort(e+1,e+n*2+1,cmp);
	map<ll,ll>::iterator it;
	int num=0;
	for(int i=1;i<=n*2;i++){
		ll x=0,y=0;
		if(e[i].size==1){
			mp[e[i].twin]++;
			num++;
		}else{
			mp[e[i].twin]++;
			mp[e[i].l]--;
		}
		if(num>=2){
			it=--mp.end();
			for(;;it--){
				if(it->second>=2 || (x && it->second!=0)){
					y=it->first;
					break;
				}
				if(!x) x=it->first;
			}
			//printf("%lld %lld\n",e[i].l,y);
			ans=max(ans,e[i].l*y*2);
		}
	}
	if(ans&1) printf("%lld.5\n",ans/2);
	else printf("%lld.0\n",ans/2);
	return 0;
}
