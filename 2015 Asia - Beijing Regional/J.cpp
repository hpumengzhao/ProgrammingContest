#include<bits/stdc++.h>

using namespace std;
int main(){
	int T;
	while(scanf("%d",&T)!=EOF){
		char s[2];int k;
		int ans=0;
		while(T--){
			scanf("%s",s);
			if(s[0]=='S') ans++;
			else{
				scanf("%d",&k);
				if(k==1) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
