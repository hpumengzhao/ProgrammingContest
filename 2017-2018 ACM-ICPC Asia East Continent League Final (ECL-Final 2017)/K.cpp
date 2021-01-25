#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const int maxn=1000000+10;
const int INF=0x3f3f3f3f;
ll L[maxn];
ll a[maxn];
ll now=0;
int main(){
	int T;
	scanf("%d",&T);
	int cas=1;
	while(T--){
		int A,B,N;
		scanf("%d %d %d",&A,&B,&N);
		for(int i=1;i<=A;i++){
			scanf("%lld",&L[i]);
		}
		ll sum=0;
		int cnt=0;
		for(int i=1;i<=A;i++){
			for(int j=1;j<=L[i];j++){
				a[++cnt]=i;
				if(cnt>A) break;
			}
			if(cnt>A) break;
		}
		int pos=A;
		for(int i=1;i<=min(A,N-1);i++){
			pos=a[pos];
		}
		int nxt=0;
		for(int i=1;i<=pos;i++){
			if(a[i]==a[pos]){
				nxt++;
			}
		}
		printf("Case #%d: %lld-%d\n",cas++,a[pos],nxt);
	}
	return 0;
}
