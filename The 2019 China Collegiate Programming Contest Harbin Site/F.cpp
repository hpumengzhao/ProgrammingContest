#include<bits/stdc++.h>

using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s[7];
	int T;
	cin>>T;
	while(T--){
		bool vis[10][26];
		memset(vis,0,sizeof(vis));
		for(int i=0;i<6;i++) cin>>s[i];
		for(int i=0;i<6;i++){
			int l=s[i].length();
			for(int j=0;j<l;j++) vis[i][s[i][j]-'a']=1;
		}
		string now="harbin";
		sort(now.begin(),now.end());
		bool jud=0;
		do{
			bool flag=0;
			for(int i=0;i<6;i++){
				if(!vis[i][now[i]-'a']){
					flag=1;
					break;
				}
			}
			if(!flag){
				jud=1;break;
			}
		}while(next_permutation(now.begin(),now.end()));
		if(jud){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
