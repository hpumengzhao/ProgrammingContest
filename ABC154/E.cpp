/*
* @author:  codancer
* @createTime:  2020-02-09, 20:16:44
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
#define pb push_back
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef pair<int,int> pii;
int cal(int n){
	int ans=0;
	while(n){
		ans+=(n%10!=0);
		n/=10;
	}
	return ans;
}
int main(){
	string s;
	int k;
	cin>>s>>k;
	int l=(int)s.length();
	if(l<=4){
		int n=0;
		int ans=0;
		for(char c:s){
			n=n*10+c-'0';
		}
		for(int i=1;i<=n;i++){
			if(cal(i)==k) ans++;
		}
		cout<<ans<<endl;
	}else{
		int x1=s[0]-'0';
		int x2=0;
		int x3=0;
		int id2=-1,id3=-1;
		int ans=0;
		for(int i=1;i<l;i++){
			if(s[i]!='0'){
				id2=i;
				x2=s[i]-'0';
				break;
			}
		}
		if(id2!=-1){
			for(int i=id2+1;i<l;i++){
				if(s[i]!='0'){
					id3=i;
					x3=s[i]-'0';
					break;
				}
			}
		}
		if(k==1){
			for(int len=1;len<=l-1;len++){
				ans+=9;
			}
			ans+=x1;
		}
		if(k==2){
			for(int len=2;len<=l-1;len++){
				ans+=9*9*(len-1);
			}
			ans+=(x1-1)*9*(l-1);
			if(x2) ans+=(l-id2-1)*9;//x1 0 ????
			ans+=x2;
		}
		if(k==3){
			for(int len=3;len<=l-1;len++){
				ans+=9*9*9*(len-1)*(len-2)/2;
			}
			if(x2==0&&x3==0){
				ans+=(x1-1)*9*9*(l-1)*(l-2)/2;//<x1 ?????
			}
			if(x2&&x3==0){
				ans+=(x1-1)*9*9*(l-1)*(l-2)/2;//<x1 ?????
				ans+=9*9*(l-id2-1)*(l-id2-2)/2;// x1 0 ????
				ans+=(x2-1)*9*(l-id2-1);// x1 <x2 ?????
			}
			if(x2==0&&x3){
				ans+=(x1-1)*9*9*(l-1)*(l-2)/2;//<x1 ?????
				ans+=(x3-1)*9*(l-id3-1);
				ans+=9*9*(l-id3-1)*(l-id3-2)/2;
			}
			if(x2&&x3){
				ans+=(x1-1)*9*9*(l-1)*(l-2)/2;//<x1 ?????
				ans+=9*9*(l-id2-1)*(l-id2-2)/2;// x1 0 ????
				ans+=(x2-1)*9*(l-id2-1);// x1 <x2 ?????
				ans+=9*(l-id3-1);//x1 x2 0 ???
				ans+=x3;//x1x2x3000000
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}