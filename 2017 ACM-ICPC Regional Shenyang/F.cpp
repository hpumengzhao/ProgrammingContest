#include<bits/stdc++.h>

using namespace std;
__int128 res[61];
void check(__int128 x){
	double a=x;
	printf("%.10lf\n",sqrt(3*(a*a-4)));
}
void print(__int128 x){
	if(x==0){
		puts("0");
		return ;
	}
	vector<int> ans;
	while(x){
		ans.push_back(x%10);
		x/=10;
	}
	reverse(ans.begin(),ans.end());
	for(int v:ans) printf("%d",v);
	puts("");
}
int main(){
	res[1]=4;
	res[2]=14;
	res[3]=52;
	for(int i=4;i<=60;i++){
		res[i]=res[i-1]*4-res[i-2];
	}
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		__int128 now=0;
		int l=(int)s.length();
		for(int i=0;i<l;i++){
			now=now*10+s[i]-'0';
		}
		for(int i=1;i<=60;i++){
			if(res[i]>=now){
				print(res[i]);break;
			}
		}
	}
	return 0;
}
