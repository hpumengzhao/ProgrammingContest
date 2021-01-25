#include<bits/stdc++.h>
using namespace std;

int ans[11][11][11][11];

int main () {
	int a, b, c, d;
	for(int i1 = 1; i1 <= 3; ++i1) {//1-2
		for(int i2 = 1; i2 <= 3; ++i2) {//1-3
			for(int i3 = 1; i3 <= 3; ++i3) {//1-4
				for(int i4 = 1; i4 <= 3; ++i4) {//2-3
					for(int i5 = 1; i5 <= 3; ++i5) {//2-4
						for(int i6 = 1; i6 <= 3; ++i6) {//3-4
							//1 s 2 b 3 p
							a = b = c = d = 0;
							if(i1 == 1)	a += 3;
							else if(i1 == 2)	b += 3;
							else if(i1 == 3) {
								a ++;
								b ++;
							}
							if(i2 == 1)	a += 3;
							else if(i2 == 2)	c += 3;
							else if(i2 == 3) {
								a ++;
								c ++;
							}
							if(i3 == 1)	a += 3;
							else if(i3 == 2)	d += 3;
							else if(i3 == 3) {
								a ++;
								d ++;
							}
							if(i4 == 1)	b += 3;
							else if(i4 == 2)	c += 3;
							else if(i4 == 3) {
								b ++;
								c ++;
							}
							if(i5 == 1)	b += 3;
							else if(i5 == 2)	d += 3;
							else if(i5 == 3) {
								b ++;
								d ++;
							}
							if(i6 == 1)	c += 3;
							else if(i6 == 2)	d += 3;
							else if(i6 == 3) {
								c ++;
								d ++;
							}
							ans[a][b][c][d]++;
						}
					}
				}
			}
		}
	}
	int T, kase = 1;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		printf("Case #%d: ", kase++);
		if(a > 9 || b > 9 || c > 9 || d > 9)	printf("Wrong Scoreboard\n");
		else if(a < 0 || b < 0 || c < 0 || d < 0) printf("Wrong Scoreboard\n");
		else {
//			printf("%d\n", ans[a][b][c][d]);
			if(ans[a][b][c][d] == 0)	printf("Wrong Scoreboard\n");
			else if(ans[a][b][c][d] == 1)	printf("Yes\n");
			else	printf("No\n");
		}
	}
	return 0;
}
