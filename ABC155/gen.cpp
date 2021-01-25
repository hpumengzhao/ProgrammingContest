/*
* @author:  codancer
* @createTime:  2020-02-17, 10:41:32
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
	srand(time(NULL));
	int n=1000;
	int k=(rand()%(n*(n-1)/2))+1;
	cout<<n<<' '<<k<<endl;
	for(int i=1;i<=n;i++){
		int x=rand()%2?-1:1;
		cout<<x*(rand()%100000)<<' ';
	}
	cout<<endl;
	return 0;
}