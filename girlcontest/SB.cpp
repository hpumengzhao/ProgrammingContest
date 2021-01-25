/*
* @author:  codancer
* @createTime:  2020-04-25, 20:35:05
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define fep(i,a,b) for(int i=(a);i>=(b);i--)
typedef vector<int> VI;
typedef vector<ll> VII;
typedef pair<int,int> pii;

int l, m, n, a[500005];

int jump(int s){
    int point=0,i=0;
    int sum=0;
    for(;i<=n;i++) {
        if(a[i]>point+s) {
            point=a[i-1];
            sum++,i--;
        }
        if(sum==m) return 0;
    }
    return 1;
}

int main(){
    while(~scanf("%d %d %d", &l, &n, &m)) {
        for(int i=0;i<n;i++) scanf("%d", &a[i]);
        a[n]=l;
        sort(a,a+n+1);
        int left =1,right = l+1, mid;
        while(right>left){
            mid=(right+left)>>1;
            if(jump(mid)) right = mid;
            else left=mid+1;
        }
        printf("%d\n", right);
    }
    return 0;
}
