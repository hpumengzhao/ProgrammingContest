#include<bits/stdc++.h>

using namespace std;
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		if(n==1) {
			printf("1 1\n1 1\n");
		}
		if(n==2){
			printf("1 3\n1 1\n1 2 1 3\n");
		}
		if(n==3){
			printf("2 3\n");
			printf("1 2\n");
			printf("1 3 2 3\n");
			printf("1 1 2 1 2 2\n");
		}
		else if(n==4){
			printf("2 5\n");
			printf("1 4\n1 5 2 5\n1 1 2 1 2 2\n1 2 1 3 2 3 2 4\n");
		}
		else if(n==5){
			printf("3 5\n3 4\n1 4 1 5\n2 4 2 5 3 5\n2 2 2 3 3 3 3 2\n3 1 2 1 1 1 1 2 1 3\n");
		}
		else if(n>=6){
			if(n&1){
				printf("%d %d\n",(n+1)/2,n);
				printf("3 4\n1 4 1 5\n2 4 2 5 3 5\n2 2 2 3 3 3 3 2\n3 1 2 1 1 1 1 2 1 3\n");
				for(int i=6;i<=n;i++){
					if(i&1){
						for(int j=1;j<i;j++) printf("%d %d ",(i+1)/2,j);
						printf("%d %d",i/2,i-1);
					}
					else{
						for(int j=i/2+1;j>=1;j--) printf("%d %d ",j,i+1); 
						for(int j=1;j<i/2-1;j++) printf("%d %d ",j,i); 
						printf("%d %d",i/2-1,i);
					}
					printf("\n");
				}
			}
			else{
				printf("%d %d\n",n/2,n+1);
				printf("3 4\n1 4 1 5\n2 4 2 5 3 5\n2 2 2 3 3 3 3 2\n3 1 2 1 1 1 1 2 1 3\n");
				for(int i=6;i<n;i++){
					if(i&1){
						for(int j=1;j<i;j++) printf("%d %d ",(i+1)/2,j);
						printf("%d %d",i/2,i-1);
					}
					else{
						for(int j=i/2+1;j>=1;j--) printf("%d %d ",j,i+1); 
						for(int j=1;j<i/2-1;j++) printf("%d %d ",j,i);
						printf("%d %d",i/2-1,i);
					}
					printf("\n");
				}
				for(int i=1;i<=n/2;i++) printf("%d %d ",i,n);
				for(int i=n/2;i>1;i--) printf("%d %d ",i,n+1); 
				printf("%d %d",1,n+1);
				printf("\n");
			}
		}
	}
	return 0;
}
