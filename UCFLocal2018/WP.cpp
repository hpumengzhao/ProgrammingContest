/*
* @author:  codancer
* @createTime:  2020-03-25, 19:57:47
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
#define eps 1e-7
typedef vector<int> VI;
typedef vector<ll> VII;
typedef pair<int,int> pii;
struct Point{
    double x,y;
    Point(double _x=0,double _y=0):x(_x),y(_y){}
    Point operator + (Point p){return Point(x+p.x,y+p.y);}
    Point operator - (Point p){return Point(x-p.x,y-p.y);}
    Point operator * (double a){return Point(a*x,a*y);}
    Point operator / (double a){return Point(x/a,y/a);}
    double norm(){return x*x+y*y;}//模的平方
    double ABS() {return sqrt(norm());}//模
}A[20],B[20];
//线段
bool onSegment(Point Pi , Point Pj , Point Q)
{
    if((Q.x - Pi.x) * (Pj.y - Pi.y) == (Pj.x - Pi.x) * (Q.y - Pi.y)  //叉乘 
       //保证Q点坐标在pi,pj之间 
       && min(Pi.x , Pj.x) <= Q.x && Q.x <= max(Pi.x , Pj.x)    
       && min(Pi.y , Pj.y) <= Q.y && Q.y <= max(Pi.y , Pj.y))
        return true;
    else
        return false;
}

vector<int> G[200];
ll dis[200];
bool vis[200];
int n;
int dij(int s,int t){
	queue<int> q;
	rep(i,0,n) dis[i]=1e9; 
	dis[s]=0;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int v:G[u]){
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	return dis[t];
}
int main(){
	cin>>n;
	rep(i,1,n){
		cin>>A[i].x>>A[i].y;
	}
	rep(i,1,n){
		cin>>B[i].x>>B[i].y;
	}
	rep(i,1,n){
		rep(j,i+1,n){
			bool ok=1;
			rep(k,1,n){
				if(onSegment(A[i],A[j],B[k])){
					ok=0;
					break;
				}
			}
			rep(k,1,n){
				if(k!=i&&k!=j&&onSegment(A[i],A[j],A[k])){
					ok=0;
					break;
				}
			}
			if(ok==1){
				G[i].pb(j);
				G[j].pb(i);
			}
		}
	}
	int ans=dij(1,n);
	if(ans==1e9){
		puts("-1");
	}
	else{
		cout<<ans<<endl;
	}
	return 0;
}