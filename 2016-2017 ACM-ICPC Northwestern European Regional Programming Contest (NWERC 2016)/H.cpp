#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll cal(string s, int c) {
	if(s == "0")	return 0;
	if(s == "1")	return 1;
	if(s[0] == '0')	return cal(s.substr(1), c-1);
	else return (1LL<<(c-1)) + (1LL<<(c-1)) - 1 - cal(s.substr(1), c-1);
}
int main () {
	string a, b;
	cin >> n >> a >> b;
	cout << cal(b, n) - cal(a, n) - 1 << endl;
	return 0;
}
