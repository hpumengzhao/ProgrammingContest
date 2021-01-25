#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int l=1;
	for(int i=2;i*i<=n;i++){
		if(n%i==0) l=i;
	}
	printf("%d\n",l*2+n/l*2);
	return 0;
}
