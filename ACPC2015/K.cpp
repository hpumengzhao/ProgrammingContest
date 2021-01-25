/*
* @author:  codancer
* @createTime:  time
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
int main(){
	int T;
	cin>>T;
	map<string,string> mps;
	string s;
	getline(cin,s);
	while(T--){
		string s;
		getline(cin,s);
		// cout<<s<<endl;
		int l=(int)s.length();
		string tt="";
		for(int i=0;i<l;i++){
			if(s[i]==' ') continue;
			tt+=s[i];
		}
		// cout<<tt<<endl;
		string a,b;
		int id=-1;
		for(int i=0;i<tt.length();i++){
			if(tt[i]=='='){
				id=i;
				break;
			}
			a+=tt[i];
		}
		// cout<<id<<endl;
		for(int i=id+1;i<tt.length();i++){
			b+=tt[i];
		}
		mps[a]=b;
		// cout<<"ok: "<<a<<' '<<b<<endl;
	}
	int m;
	cin>>m;
	while(m--){
		string s;
		int k;
		cin>>k;
		getline(cin,s);
		getline(cin,s);
		// cout<<s<<endl;
		vector<string> now;
		string tmp="";
		for(int i=0;i<s.length();i++){
			if(s[i]!=' '){
				tmp+=s[i];
			}else{
				now.pb(tmp);
				tmp="";
			}
		}
		if(tmp!=""){
			now.pb(tmp);
		}
		// cout<<"siz: "<<now.size()<<endl;
		int siz=SZ(now);
		// cout<<now[0]<<endl;
		cout<<mps[now[0]];
		for(int i=1;i<siz;i++){
			cout<<' '<<mps[now[i]];
		}
		cout<<endl;
	}
	return 0;
}