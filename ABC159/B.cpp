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
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define fep(i,a,b) for(int i=(a);i>=(b);i--)
typedef vector<int> VI;
typedef pair<int,int> pii;
bool ok(string s){
	string t=s;
	reverse(s.begin(),s.end());
	return s==t;
}
int main(){
	double L;
	cin>>L;
	double a=L/3;
	double b=L/3;
	double c=(L-a-b);
	printf("%.12lf\n",a*b*c);
	return 0;
}

