#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10;
int a[maxn];
int b[maxn];
int ans1[maxn];
int ans2[maxn];
void change(int x){
	int pos=a[x];
	if(pos==1) return ;
	int y=b[pos-1];
	a[x]--;
	a[y]++;
	swap(b[pos],b[pos-1]);
	ans1[y]=max(ans1[y],a[y]);
	ans2[x]=min(ans2[x],a[x]);
}
int main()
{
	int n,m,x;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		a[i]=b[i]=ans1[i]=ans2[i]=i;
	}
	for(int i=0;i<m;i++){
		scanf("%d",&x);
		change(x);
	}
	for(int i=1;i<=n;i++){
		printf("%d %d\n",ans2[i],ans1[i]);
	}
	return 0;
}
