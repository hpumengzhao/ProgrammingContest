/*
* @author:  codancer
* @createTime:  2020-04-10, 18:56:34
*/
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
void solve(){
	int h,a,H,A;
	scanf("%d%d%d%d",&h,&a,&H,&A);
	if(a>=H||A==0){
		puts("-1");
		return ;
	}
	int ans=0;
	int nowh=H;
	bool turn=1;
	rep(i,1,100000){
		if(h<=0){
			break;
		}
		if(turn){
			nowh-=a;
			if(nowh<=0){
				++ans;
				nowh=H;
			}else{
				turn=0;
			}
		}
		else{
			h-=A;
			turn=1;
		}
	}
	printf("%d\n", ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}