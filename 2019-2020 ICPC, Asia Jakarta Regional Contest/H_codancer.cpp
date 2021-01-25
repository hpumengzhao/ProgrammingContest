#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N = 1e6+100;
struct node{
	ll l,w,id;
}s[N];
bool cmp(node a,node b){
	if(a.l==b.l) return a.w<b.w;
	return a.l<b.l;
}
struct seg{
	ll maxx[N<<1];
	void pushup(int rt){
		maxx[rt]=max(maxx[rt<<1],maxx[rt<<1|1]);
	}
	void bt(int rt,int l,int r){
		maxx[rt]=0;
		if(l==r){
			maxx[rt]=s[l].w;
			return ;
		}
		int mid=(l+r)>>1;
		bt(rt<<1,l,mid);
		bt(rt<<1|1,mid+1,r);
		pushup(rt);
	}
	ll query(int rt,int l,int r,int nl,int nr){
		if(nl<=l&&r<=nr){
			return maxx[rt];
		}
		ll ans=0;
		int mid=(l+r)>>1;
		if(nl<=mid) ans=max(ans,query(rt<<1,l,mid,nl,nr));
		if(nr>mid) ans=max(ans,query(rt<<1|1,mid+1,r,nl,nr));
		return ans;
	}
}tree;
int pos[N];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		 scanf("%lld %lld",&s[i].l,&s[i].w);s[i].id=i;
	}
	for(int i=n+1;i<=2*n;i++){
		s[i].l=s[i-n].w;
		s[i].w=s[i-n].l;
		s[i].id=i;
	}
	sort(s+1,s+2*n+1,cmp);
	for(int i=1;i<=2*n;i++){
		pos[s[i].id]=i;
	}
	tree.bt(1,1,2*n);
	ll ans=0;
	for(int i=1;i<=2*n;i++){
		ll xx=s[i].w;
		if(s[i].id>n){
			if(pos[s[i].id-n]>i){
				if(pos[s[i].id-n]<2*n){
					int p=pos[s[i].id-n];
					ll yy=max(tree.query(1,1,2*n,i+1,p-1),tree.query(1,1,2*n,p+1,2*n));
					ans=max(ans,s[i].l*min(xx,yy));
					continue;
				}
				if(pos[s[i].id-n]==2*n){
					int p=pos[s[i].id-n];
					ll yy=tree.query(1,1,2*n,i+1,2*n-1);
					ans=max(ans,s[i].l*min(xx,yy));
					continue;					
				}
			}
			else{
				ll yy=tree.query(1,1,2*n,i+1,2*n);
				ans=max(ans,s[i].l*min(xx,yy));
				continue;					
			}
		}else{
			//cout<<i<<' '<<pos[s[i].id+n]<<endl;
			if(pos[s[i].id+n]>i){
				if(pos[s[i].id+n]<2*n){
					int p=pos[s[i].id+n];
					ll yy=max(tree.query(1,1,2*n,i+1,p-1),tree.query(1,1,2*n,p+1,2*n));
					ans=max(ans,s[i].l*min(xx,yy));
					continue;
				}
				if(pos[s[i].id+n]==2*n){
					int p=pos[s[i].id+n];
					ll yy=tree.query(1,1,2*n,i+1,2*n-1);
					ans=max(ans,s[i].l*min(xx,yy));
					continue;					
				}
			}
			else{
				ll yy=tree.query(1,1,2*n,i+1,2*n);
				ans=max(ans,s[i].l*min(xx,yy));
				continue;					
			}		
		}
	}
	ll ans2=0;
	for(int i=1;i<=2*n;i++){
		ans2=max(ans2,s[i].l*s[i].w);
	}
	if(ans*2>ans2){
		printf("%lld.0\n",ans);
	}
	else{
	    if(ans2&1){
	        printf("%lld.5",ans2/2);
	    }else{
	        printf("%lld.0\n",ans2/2);
	    }
	}
	return 0;
}
