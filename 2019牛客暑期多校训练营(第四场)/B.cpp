#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1000000+10;
int n,m,N,sz;
int x;
int tree[maxn][35];
void init(int x){
    N=1;
    while(N<x) N*=2;
}
void add(int k,int x){
    for(int i=31;i>=0;i--){
        if(x>>i){
            if(!tree[k][i]){
                tree[k][i]=x;
                break;
            }
            x^=tree[k][i];
        }
    }
}
void LinearBase(int v1,int v2,int res){
    int a[35],b[35];
    for(int i=0;i<32;i++) a[i]=b[i]=tree[v1][i];
    for(int i=0;i<32;i++){
        int q=tree[v2][i],t=0;
        if(!q) continue;
        int j=i;
        for(;j>=0;j--){
            if(q>>j){
                if(!a[j]) break;
                q^=a[j];
                t^=b[j];
            }
        }
        if(!q) tree[res][i]=t;
        else a[j]=q,b[j]=t;
    }
}
void build(int l,int r,int k){
    if(l==r) return ;
    build(l,(l+r)/2,k*2+1);
    build((l+r)/2+1,r,k*2+2);
    LinearBase(k*2+1,k*2+2,k);
}
bool check(int k,int x){
    for(int i=31;i>=0;i--){
        if(x>>i){
            if(!tree[k][i]) return false;
            x^=tree[k][i];
        }
    }
    return true;
}
bool query(int a,int b,int x,int l,int r,int k){
    if(r<a || b<l) return true;
    if(a<=l && r<=b) return check(k,x);
    else{
        bool vl=query(a,b,x,l,(l+r)/2,k*2+1);
        bool vr=query(a,b,x,(l+r)/2+1,r,k*2+2);
        return vl&vr;
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    init(n);
    for(int i=0;i<n;i++){
        scanf("%d",&sz);
        for(int j=0;j<sz;j++){
            scanf("%d",&x);
            add(i+N-1,x);
        }
    }
    build(0,N-1,0);
    int l,r;
    while(m--){
        scanf("%d %d %d",&l,&r,&x);
        l--,r--;
        if(query(l,r,x,0,N-1,0)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
