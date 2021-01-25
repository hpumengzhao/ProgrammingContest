/*
* @author:  codancer
* @createTime:  2020-02-24, 11:15:44
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
int trans(string s){
	int ans=0;
	for(int i=0;i<(int)s.length();i++){
		ans=ans*10+s[i]-'0';
	}
	return ans;
}
int main(){
	string a,b;
	cout<<"Input ip:"<<endl;
	cin>>a;
	cout<<"Input yanma"<<endl;
	cin>>b;
	int n=(int)a.length();
	int m=(int)b.length();
	vector<int> x,y;
	string now="";
	for(int i=0;i<n;i++){
		if(a[i]!='.'){
			now+=a[i];
		}else{
			x.pb(trans(now));
			now="";
		}
	}
	x.pb(trans(now));
	now="";
	for(int i=0;i<m;i++){
		if(b[i]!='.'){
			now+=b[i];
		}else{
			y.pb(trans(now));
			now="";
		}
	}
	y.pb(trans(now));
	int siz=(int)x.size();
	vector<int> id;
	for(int i=0;i<siz;i++){
		id.pb(x[i]&y[i]);
	}
	cout<<"Internet adress is"<<endl;
	cout<<id[0];
	for(int i=1;i<siz;i++){
		cout<<"."<<id[i];
	}
	cout<<endl;
	system("pause");
	return 0; 
}
