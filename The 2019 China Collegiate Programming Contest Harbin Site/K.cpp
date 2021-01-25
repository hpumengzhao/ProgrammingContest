#include<bits/stdc++.h>

using namespace std;
const int N = 2e5+100;
double w[N];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		long long n,k;
		scanf("%lld %lld",&n,&k);
		double s=0;
		for(int i=1;i<=n;i++){
			scanf("%lf",&w[i]);
			s+=w[i];
		}
		for(int i=1;i<=n;i++){
			if(i==1){
				printf("%.10lf",w[i]+w[i]*k/s);
			}else{
				printf(" %.10lf",w[i]+w[i]*k/s);	
			}
		}
		puts("");
	}
	return 0;
}
