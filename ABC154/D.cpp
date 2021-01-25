/*
* @author:  codancer
* @createTime:  2020-02-09, 20:08:29
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
double cal(int x){
	double now = x*(x+1)/2.0;
	now/=x;
	return now;
}
int main(){
	int n,k;
	cin>>n>>k;
	VI a(n+1);
	vector<double> pre(n+1);
	vector<double> x;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]+cal(a[i]);
	}
	double ans=0;
	for(int i=k;i<=n;i++){
		ans=max(ans,pre[i]-pre[i-k]);
	}
	printf("%.10lf\n",ans);
	return 0;
}