#include<bits/stdc++.h>

using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		string s;
		int n;
		int nx=0,ny=0;
		map<pair<int,int>,int> vis;
		cin>>n>>s;
		vis[{0,0}]=0;
		int ans=1e9;
		int al,ar;
		for(int i=0;i<n;i++){
			if(s[i]=='L') --nx;
			if(s[i]=='R') ++nx;
			if(s[i]=='U') ++ny;
			if(s[i]=='D') --ny;
			if(vis.count({nx,ny})&&(i-vis[{nx,ny}]<ans)){
				al=vis[{nx,ny}]+1;
				ar=i+1;
				vis[{nx,ny}]=i;
			}
		}
		if(ans==1e9){
			cout<<-1<<endl;
		}else{
			cout<<al<<' '<<ar<<endl;
		}
	}
	return 0;
}
