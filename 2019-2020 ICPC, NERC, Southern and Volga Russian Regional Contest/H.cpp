#include<bits/stdc++.h>

using namespace std;

int a[233];
int main() {
	int T;
	cin >> T;
	while(T--){
		int pos = 0;
		for(int i = 0; i <= 9; ++i) {
			cin >> a[i];
			if(a[pos] > a[i])	pos = i;
		}
		int p = 1;
		for(int i = 1; i <= 9; ++i) if(a[p] > a[i])	p = i;
		if(pos == 0 && a[p] != a[pos]) {
			int pos2 = -1;
			for(int i = 1; i <= 9; ++i) {
				if(a[i] != 0){
					pos2 = i;
					break;
				}
			}
			if(pos2 == -1)	cout << 1 << endl;
			else {
				cout << pos2;
				for(int i = 1; i <= a[0] + 1; ++i)	cout << 0;
				cout << endl;
			}
		} else if(a[p] == a[pos]){
			for(int i = 1; i <= a[p] + 1; ++i)	cout << p;
			cout << endl;
		} else {
			for(int i = 1; i <= a[pos] + 1; ++i)	cout << pos;
			cout << endl;
		}
	}
	return 0;
}
