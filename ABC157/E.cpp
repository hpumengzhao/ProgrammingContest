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
const int N = 6e5+100;
struct Seg{
    ll sum[N<<1],add[N<<1];
    inline void pushup(ll rt){
        sum[rt]=sum[rt<<1]+sum[rt<<1|1];
    }
    inline void pushdown(ll rt,ll l,ll r){
        if(add[rt]){
            ll mid=(l+r)>>1;
            sum[rt<<1]=sum[rt<<1]+add[rt]*(mid-l+1);
            sum[rt<<1|1]=sum[rt<<1|1]+add[rt]*(r-mid);

            add[rt<<1]+=add[rt];
            add[rt<<1|1]+=add[rt];

            add[rt]=0;
        }
        return ;
    }
    inline void buildtree(ll rt,ll l,ll r){
        add[rt]=0;
        if(l==r){
            sum[rt]=0;
            return ;
        }
        ll mid=(l+r)>>1;
        buildtree(rt<<1,l,mid);
        buildtree(rt<<1|1,mid+1,r);
        pushup(rt);
    }
    inline void modify(ll rt,ll l,ll r,ll nl,ll nr,ll k){//Çø¼ä[nl,nr]+k
        if(nl<=l&&r<=nr){
            add[rt]+=k;
            sum[rt]+=k*(r-l+1);
            return ;
        }
        ll mid=(l+r)>>1;
        pushdown(rt,l,r);
        if(nl<=mid) modify(rt<<1,l,mid,nl,nr,k);
        if(nr>mid) modify(rt<<1|1,mid+1,r,nl,nr,k);
        pushup(rt);
    }
    inline ll querysum(ll rt,ll l,ll r,ll nl,ll nr){
         if(nl<=l&&r<=nr){
            return sum[rt];
        }
        ll ans=0;
        ll mid=(l+r)>>1;
        pushdown(rt,l,r);
        if(nl<=mid) ans+=querysum(rt<<1,l,mid,nl,nr);
        if(nr>mid) ans+=querysum(rt<<1|1,mid+1,r,nl,nr);
        return ans;       
    }
}tree[26];
char s[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n>>(s+1);
	for(int i=0;i<26;i++){
		tree[i].buildtree(1,1,n);
	}
	for(int i=1;i<=n;i++){
		tree[s[i]-'a'].modify(1,1,n,i,i,1);//+1
	}
	int m;
	cin>>m;
	int op,l,r;
	char ss;
	while(m--){
		cin>>op;
		if(op==2){
			cin>>l>>r;
			int ans=0;
			for(int i=0;i<26;i++){
				if(tree[i].querysum(1,1,n,l,r)) ++ans;
			}
			cout<<ans<<endl;
		}else{
			cin>>l>>ss;
			tree[s[l]-'a'].modify(1,1,n,l,l,-1);
			tree[ss-'a'].modify(1,1,n,l,l,1);
			s[l]=ss;
		}
	}
	return 0;
}

