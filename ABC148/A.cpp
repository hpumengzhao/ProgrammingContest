#include<bits/stdc++.h>

using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	bool vis[4];
	memset(vis,0,sizeof(vis));
	vis[a]=vis[b]=1;
	for(int i=1;i<=3;i++){
		if(!vis[i]){
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}

