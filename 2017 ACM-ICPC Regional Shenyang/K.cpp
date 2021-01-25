#include<bits/stdc++.h>

using namespace std;
int a[10000+10];
int main(){
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		printf("%d\n",(a[n]-a[1]+1-n)-min((a[2]-a[1]),a[n]-a[n-1])+1);
	}
	return 0;
}
