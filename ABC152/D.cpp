#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll num[9][9];
void init(int n){
	for(int i=1;i<=n;i++){
		int x=i;
		vector<int> now;
		while(x){
			now.push_back(x%10);
			x/=10; 
		}
		int siz=(int)now.size();
		num[now[0]][now[siz-1]]++;
	}
}
int main(){
	int n;
	cin>>n;
	memset(num,0,sizeof(num));
	init(n);
	long long ans=0;
	for(int fi=1;fi<=9;fi++){
		for(int la=1;la<=9;la++){
			ans+=num[fi][la]*num[la][fi]; 
		}
	}
	cout<<ans<<endl;
	return 0;
}

