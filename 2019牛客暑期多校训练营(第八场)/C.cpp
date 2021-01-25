#include<bits/stdc++.h>
#define rep(i, a, b)    for(int i = (a); i <= (int)(b); ++i)
#define per(i, a, b)    for(int i = (a); i >= (int)(b); --i)
#define debug(x)    cerr << #x << ' ' << x << endl;
using namespace std;
 
typedef long long ll;
const int MAXN = 1e6 + 7;
 
int mat[11][2050][2050];
 
int main(){
    mat[1][1][1] = 1;
    mat[1][1][2] = 1;
    mat[1][2][1] = 1;
    mat[1][2][2] = -1;
    int n = 2;
    while(n<=10){
        rep(i, 1, 1<<(n-1)){
            rep(j, 1, 1<<(n-1)){
                mat[n][i][j] = mat[n-1][i][j];
            }
        }
        rep(i, (1<<(n-1))+1, 1<<n){
            rep(j, 1, 1<<(n-1)){
                mat[n][i][j] = mat[n-1][i-(1<<(n-1))][j];
            }
        }
        rep(i, 1, 1<<n){
            rep(j, (1<<(n-1))+1, 1<<n){
                mat[n][i][j] = mat[n-1][i][j-(1<<(n-1))];
            }
        }
        rep(i, (1<<(n-1))+1, 1<<n){
            rep(j, (1<<(n-1))+1, 1<<n){
                mat[n][i][j] = -mat[n-1][i-(1<<(n-1))][j-(1<<(n-1))];
            }
        }
        n++;
    }
    scanf("%d", &n);
    n = log2(n);
    rep(i, 1, 1<<n){
        rep(j, 1, 1<<n){
            printf("%d%c", mat[n][i][j], j == (1<<n)?'\n':' ');
        }
    }
    return 0;
}
