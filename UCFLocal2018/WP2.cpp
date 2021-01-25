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
struct Segment{
    Point p1,p2;
};
//点积
double dot(Point a,Point b){
    return a.x*b.x+a.y*b.y;
}
//叉积
double cross(Point a,Point b){
    return a.x*b.y-a.y*b.x;
}
double Pointdis(Point a,Point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double Segdis(Point A ,Segment B){
    Point alp1=A-B.p1;
    Point beta1=B.p2-B.p1;
    Point alp2=A-B.p2;
    Point beta2=B.p1-B.p2;
    if(dot(alp1,beta1)<0||dot(alp2,beta2)<0){
        return min(Pointdis(A,B.p1),Pointdis(A,B.p2));
    }
    double a=B.p1.y-B.p2.y;
    double b=B.p2.x-B.p1.x;
    double c=B.p1.y*(B.p1.x-B.p2.x)-B.p1.x*(B.p1.y-B.p2.y);
    return fabs(a*A.x+b*A.y+c)/sqrt(a*a+b*b);
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
			Segment x;
			x.p1=A[i];
			x.p2=A[j];
			bool ok=1;
			rep(k,1,n){
				if(Segdis(B[k],x)==0){
					ok=0;
					break;
				}
			}
			rep(k,1,n){
				if(k!=i&&k!=j&&Segdis(A[k],x)==0){
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