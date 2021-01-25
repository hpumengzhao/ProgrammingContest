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
const int N = 2e4+100;
struct node{
	int a,b;
	int id;
}s[N];
bool cmp(node a,node b){
	if(a.a==b.a) return a.b<b.b;
	return a.a<b.a;
}
pair<int,int> vase[N];
int ans[N];
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
		s[i].id=i;
		if(s[i].a>s[i].b) swap(s[i].a,s[i].b);
	}
	for(int i=1;i<=k;i++){
		cin>>vase[i].first;
		vase[i].second=i;
	}
	sort(s+1,s+n+1,cmp);
	// for(int i=1;i<=n;i++) cout<<s[i].a<<' '<<s[i].b<<endl;
	sort(vase+1,vase+k+1);
	int i=1,j=1;
	while(i<=n&&j<=k){
		if(vase[j].first==s[i].a||vase[j].first==s[i].b){
			ans[vase[j].second]=s[i].id;
			++i;
			++j;
		}else{
			++i;
		}
	}
	if(j==k+1){
		for(int i=1;i<=k;i++){
			cout<<ans[i]<<endl;
		}
	}else{
		cout<<"impossible"<<endl;
	}
	return 0;
}