#include<bits/stdc++.h>
using namespace std;
long long a[62][61],n,m;
long long dfs(int n,int m){
	if(a[n][m]!=-1) return a[n][m];//记忆化
	if(m==1){
		return a[n][m]=1;
	}
	if(n==m){
		return a[n][m]=1;
	}
	return a[n][m]=dfs(n-1,m-1)+m*dfs(n-1,m);
}
int main()
{
    cin>>n>>m;
    memset(a,-1,sizeof(a));
    cout<<dfs(n,m)<<endl;
 return 0;
}