/*
* @author:  codancer
* @createTime:  time
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
};
struct Segment{
    Point p1,p2;
};
vector<Point> CCL(Segment s,Point o,double r){
	vector<Point> res;
	Point x=Projection(o,s);
	double dis=PLDis(o,s);
	if(dis>r){//距离>r没有交点
		return res;
	}
	if(dis==r){//只有一个交点
		res.push_back(x);
		res.push_back(x);
	}
		double beta=sqrt(r*r-dis*dis);//勾股定理
		Point pp=s.p2-s.p1;
		pp=pp/pp.ABS();//单位向量
		Point ans1=x-pp*beta;
		Point ans2=x+pp*beta;
		res.push_back(ans1);
		res.push_back(ans2);
	return res;
}
int main(){
	Point a;
	double r;
	cin>>a.x>>a.y>>r;
	double sx,sy;
	double t;
	return 0;
}