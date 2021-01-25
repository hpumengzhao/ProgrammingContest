#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const int INF=0x3f3f3f3f;
const int maxn=1000000+10;
struct point{
	ll x,y;	
}p[maxn];
ll cal(point a,point b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%lld %lld",&p[i].x,&p[i].y);
	}
	vector<int> all;
	point now;
	while(q--){
		ll minn=0x3f3f3f3f3f3f3f3f;
		scanf("%lld %lld",&now.x,&now.y);
		for(int i=1;i<=n;i++){
			minn=min(minn,cal(p[i],now));
		}
		all.clear();
		bool flag=0;
		for(int i=1;i<=n;i++){
			if(cal(p[i],now)==minn){
				all.push_back(i);
			}
			if(all.size()>=3) break;
		}
		if(all.size()==0){
			puts("NONE");
		}
		if(all.size()==1){
			printf("REGION %d\n",all[0]);
		}
		if(all.size()==2){
			printf("LINE %d %d\n",all[0],all[1]);			
		}
		if(all.size()==3){
			puts("POINT");
		}
	}
	return 0;
}
