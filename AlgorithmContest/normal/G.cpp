/*
* @author:  codancer
* @createTime:  2020-04-04, 11:00:50
*/
#pragma GCC optimize(3)

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define fep(i,a,b) for(int i=(a);i>=(b);i--)
typedef vector<int> VI;
typedef vector<ll> VII;
typedef pair<int,int> pii;
int w[4000];
struct Seg{
    ll maxx[10000];
    inline void pushup(ll rt){
        maxx[rt]=max(maxx[rt<<1|1],maxx[rt<<1]);
    }
    inline void buildtree(ll rt,ll l,ll r){
        if(l==r){
        	maxx[rt]=w[l];
            return ;
        }
        ll mid=(l+r)>>1;
        buildtree(rt<<1,l,mid);
        buildtree(rt<<1|1,mid+1,r);
        pushup(rt);
    }
    inline ll querymaxx(ll rt,ll l,ll r,ll nl,ll nr){
        if(nl<=l&&r<=nr){
            return maxx[rt];
        }
        ll ans=0;
        ll mid=(l+r)>>1;
        if(nl<=mid) ans=max(ans,querymaxx(rt<<1,l,mid,nl,nr));
        if(nr>mid) ans=max(ans,querymaxx(rt<<1|1,mid+1,r,nl,nr));
        return ans;
    }
}tree;
int RR[3000][502];//前i个<=j和>=j的个数
int num[3000][502];
int ans[2001][2001];
set<pair<int,int> > st[510]; 
int main(){
	int n;
	cin>>n;
	vector<int> a(n+1);
	int ok=0;
	rep(i,1,n){
		cin>>a[i];
	}
	if(ok){
		int m;
		cin>>m;
		int x,y;
		rep(i,1,m){
			cin>>x>>y;
			cout<<"NO"<<endl;
		}
		return 0;
	}
	rep(i,1,n){
		rep(j,1,500){
			RR[i][j]=RR[i-1][j];
		}
		rep(j,1,a[i]){
			RR[i][j]=RR[i-1][j]+1;
		}
	}
	rep(L,1,n){
		rep(R,L,n){
			if((R-L+1)&1){
				int num=(R-L)/2;
				int l=1;
				int r=201;
				int res;
				rep(j,1,10){
					int mid=(l+r)>>1;
					if(RR[R][mid]-RR[L-1][mid]>num){
						l=mid;
					}
					else{
						r=mid;
					}
				}
				ans[L][R]=r-1;
				if(RR[R][r-1]-RR[l-1][r-1]) st[r-1].insert({L,R});
			}
		}
	}
	rep(i,1,n){
		w[i]=1;
		for(auto v:st[a[i]]){
			if(v.first<=i&&i<=v.second){
				w[i]=max(w[i],v.second-v.first+1);
			}
		}
	}
	tree.buildtree(1,1,n);
	int m;
	cin>>m;
	rep(i,1,m){
		int l,r;
		cin>>l>>r;
		cout<<tree.querymaxx(1,1,n,l,r)<<endl;
	}
	return 0;
}