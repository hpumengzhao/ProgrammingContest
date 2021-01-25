#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		if(n<=5){
			puts("-1");
			continue;
		}
		if(n&1){
			printf("%d %d\n",3,n-3);
			continue;
		}
		printf("%d %d\n",2,n-2);
	}
	return 0;
}
