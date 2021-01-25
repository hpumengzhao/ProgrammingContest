/*
* @author:  codancer
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
	int a[3][3];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cin>>a[i][j];
		}
	}
	map<int,int> mp;
	int n,x;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		mp[x]=1;
	}
	bool bingo=0;
	for(int i=0;i<3;i++){
		if(mp[a[i][0]]&&mp[a[i][1]]&&mp[a[i][2]]) bingo=1;
	}
	for(int i=0;i<3;i++){
		if(mp[a[0][i]]&&mp[a[1][i]]&&mp[a[2][i]]) bingo=1;
	}
	if(mp[a[1][1]]&&mp[a[0][0]]&&mp[a[2][2]]) bingo=1;
	if(mp[a[0][2]]&&mp[a[1][1]]&&mp[a[2][0]]) bingo=1;
	if(bingo){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}

