/*
* @author:  codancer
* @createTime:  2020-02-16, 20:02:56
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
	int n;
	cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]%2==0){
			if((a[i]%3)&&(a[i]%5)){
				cout<<"DENIED"<<endl;
				return 0;
			}
		}
	}
	cout<<"APPROVED"<<endl;
	return 0;
}