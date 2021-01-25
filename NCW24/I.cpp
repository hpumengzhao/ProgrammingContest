#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+1000; 
struct edge
{
	ll next,to;
}e[N<<2];
struct  node
{
	ll l,r,w,siz,lazy; 
}tr[N<<2];
ll idx,root,cnt=0,n,m;
ll a[N];
ll dep[N],fa[N],son[N],size[N],top[N],id[N],rk[N];
ll h[N];
void add(ll u,ll v)
{
	e[++idx].to=v;e[idx].next=h[u];h[u]=idx;
 } 
void dfs1(ll u,ll father,ll depth )
 {
 	dep[u]=depth;fa[u]=father;size[u]=1;
 	ll maxn=-1; 
 	for(ll i=h[u];~i;i=e[i].next)
 	{
 		ll j=e[i].to;
 		if(j==father) continue;
 		dfs1(j,u,depth+1);
 		size[u]+=size[j];
 		if(size[j]>maxn) 
 		{
 			maxn=size[j];
 			son[u]=j;
		 }
	 }
 }
 void dfs2(ll u,ll v)
 {
 	top[u]=v;
	id[u]= ++cnt;
	rk[cnt]=a[u];
	if(!son[u]) return ;
	dfs2(son[u],v);
	for(ll i=h[u];~i;i=e[i].next)
	{
		ll j=e[i].to;
		if(j!=son[u]&&j!=fa[u]) dfs2(j,j);
	 } 
 	
 }
 void push_up(ll u)
 {
 	tr[u].w=(tr[u<<1].w+tr[u<<1|1].w);
 }
 void build(ll u,ll l,ll r)
 {
 	tr[u].l=l;tr[u].r=r;tr[u].siz=r-l+1;
 	if(l==r)
 	{
 		tr[u].w=rk[l];
 		return ;
 		
	 }
	 ll mid=l+r>>1;
	 build(u<<1,l,mid);build(u<<1|1,mid+1,r);
	 push_up(u);
 }
 void push_down(ll u)
 {
 	if(tr[u].lazy)
 	{

 		tr[u<<1].w=(tr[u<<1].w+tr[u<<1].siz*tr[u].lazy);
		tr[u<<1|1].w=(tr[u<<1|1].w+tr[u<<1|1].siz*tr[u].lazy);
		tr[u<<1].lazy=(tr[u<<1].lazy+tr[u].lazy);
		tr[u<<1|1].lazy=(tr[u<<1|1].lazy+tr[u].lazy);
		tr[u].lazy=0;
	 }
 }
 void lleradd(ll u,ll l,ll r,ll val)
 {
 	if(l<=tr[u].l&&tr[u].r<=r)
 	{
 		tr[u].w+=tr[u].siz*val;
 		tr[u].lazy+=val;
 		return ;
	 }
	 push_down(u);
	 ll mid=tr[u].l+tr[u].r>>1;
	 if(l<=mid) lleradd(u<<1,l,r,val);
	 if(r>mid) lleradd(u<<1|1,l,r,val);
	 push_up(u);
  } 
 void treeadd(ll x,ll y,ll val)
 {
 	while(top[x]!=top[y])
 	{
 		if(dep[top[x]]<dep[top[y]]) swap(x,y);
 		lleradd(1,id[top[x]],id[x],val);
 		x=fa[top[x]];
	 }
	 if(dep[x]>dep[y]) swap(x,y);
	 lleradd(1,id[x],id[y],val);
 }
 ll Insum(ll u,ll l,ll r)
 {
 	ll ans=0;
 	if(l<=tr[u].l&&tr[u].r<=r) return tr[u].w;
	push_down(u);
 	ll mid=tr[u].l+tr[u].r>>1;
 	if(l<=mid) ans=(ans+Insum(u<<1,l,r));
    if(r>mid) ans=( ans+Insum(u<<1|1,l,r));
	return ans;
 }
int main()
{
	memset(h,-1,sizeof h);
	scanf("%lld %lld %lld",&n,&m,&root);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(ll i=1;i<=n-1;i++)
	{
		ll x,y;
		scanf("%lld %lld",&x,&y);
		add(x,y);add(y,x);
	}
	dfs1(root,0,1);
	dfs2(root,root); 
	build(1,1,n); 
	while(m--)
	{
		ll op,x,y,z;
		scanf("%lld",&op);
		if(op==1)
		{
			scanf("%lld %lld",&x,&z); 
			treeadd(x,x,z);
		}
		else if(op==2)
		{
			scanf("%lld",&x);
			printf("%lld\n",Insum(1,id[x],id[x]+size[x]-1));
		}
	}
 } 
