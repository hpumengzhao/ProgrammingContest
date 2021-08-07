/*
* @author:  codancer
* @createTime:  2021-08-07, 15:52:29
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9+7;
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define fep(i,a,b) for(int i=(a);i>=(b);i--)
#define deb(x) cerr<<#x<<" = "<<(x)<<"\n"
typedef vector<int> VI;
typedef vector<ll> VII;
typedef pair<int,int> pii;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll Rand(ll B) {
    return (ull)rng() % B;
}
const int N = 33;
int dp[N][N][N];
bool ndp[N][N];
char c[N][N];
int a[N][N];
void solve(){
    int n;
    cin>>n;
    rep(i,1,n){
        rep(j,1,n){
            a[i][j]=0;
            ndp[i][j]=0;
            cin>>c[i][j];
            if(c[i][j]=='.') a[i][j]=1;
        }
    }
    rep(i,1,n){
        if(c[1][i]=='.') ndp[1][i]=1;
        else break;
    }
    rep(i,1,n){
        if(c[i][1]=='.') ndp[i][1]=1;
        else break;
    }
    rep(i,2,n){
        rep(j,2,n){
            if(c[i][j]=='.'){
                ndp[i][j]=(ndp[i][j-1]|ndp[i-1][j]);
            }
        }
    }
    if(ndp[n][n]==0){
        cout<<0<<endl;
        return ;
    }
    rep(t,0,2*n){
        rep(i,1,n){
            rep(j,1,n) dp[i][j][t]=0;
        }
    }
    dp[1][1][1]=a[1][1];
    for(int k=2;k<=(n*2)-1;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int n1=dp[i][j][k-1];
                int n2=dp[i-1][j][k-1];
                int n3=dp[i][j-1][k-1];
                int n4=dp[i-1][j-1][k-1];
                int tmp=max(max(n1,n2),max(n3,n4));
                if(i!=j) dp[i][j][k]=tmp+a[i][k-i+1]+a[j][k-j+1];
                else dp[i][j][k]=tmp+a[i][k-i+1];
            }
        }
    }
    if(dp[n][n][2*n-1]==4*n-4){
        cout<<2<<endl;
        return ;
    }
    cout<<1<<endl;

}   
int main(){
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}