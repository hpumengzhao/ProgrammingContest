#include<bits/stdc++.h>

using namespace std;
struct re{
	int x[3];
}s[10];
bool check(re a,re b,re c){
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				if(a.x[i]==b.x[j] && b.x[j]==c.x[k]) return true;
				if(a.x[i]==b.x[j]+c.x[k] && b.x[1-j]==c.x[1-k]) return true;
				if(b.x[j]==a.x[i]+c.x[k] && a.x[1-i]==c.x[1-k]) return true;
				if(c.x[k]==a.x[i]+b.x[j] && b.x[1-j]==a.x[1-i]) return true;
			}
		}
	}
	return false;
}
int main(){
	int T;
	while(~scanf("%d",&T)) {
		while(T--){
			for(int i=1;i<=4;i++) scanf("%d %d",&s[i].x[0],&s[i].x[1]);
			bool flag = 0;
			for(int i=1;i<=4;i++){
				for(int j=i+1;j<=4;j++){
					for(int k=j+1;k<=4;k++){
						if(check(s[i],s[j],s[k])) flag=1;
					}
				}
			}
			if(flag)	printf("Yes\n");
			else	printf("No\n");
		}
	}
	return 0;
}
