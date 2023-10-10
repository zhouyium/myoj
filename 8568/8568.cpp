#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=2e6+10;

int sgn(double x) {
	if(fabs(x)<EPS)return 0;
	return x<0?-1:1;
}
struct Point { //定义点和基本运算
	double x,y;
	double ang;
	Point() {}
	Point(double x,double y):x(x),y(y) {}
	Point operator + (Point B) {
		return Point(x+B.x,y+B.y);
	}
	Point operator - (Point B) {
		return Point(x-B.x,y-B.y);
	}
	Point operator * (double k) {
		return Point(x*k,y*k);   //长度增大k倍
	}
	Point operator / (double k) {
		return Point(x/k,y/k);   //长度缩小k倍
	}
	bool operator == (Point B) {
		return sgn(x-B.x)==0 && sgn(y-B.y)==0;
	}
	double operator ^(Point B) {
		return x*B.y-y*B.x;
	}
	double distance(Point p) {
		return hypot(x-p.x,y-p.y);
	}
	double len() {
		return hypot(x,y);//库函数
	}
	Point trunc(double r) {
		double l = len();
		if(!sgn(l))return *this;
		r /= l;
		return Point(x*r,y*r);
	}//点积
	double operator *(const Point &b)const {
		return x*b.x + y*b.y;
	}
	double len2() {
		return x*x + y*y;
	}
	double rad(Point a,Point b) {
		Point p = *this;
		return fabs(atan2( fabs((a-p)^(b-p)),(a-p)*(b-p) ));
	}

};

typedef Point Vector;
double Cross(Vector A,Vector B) {
	return A.x*B.y - A.y*B.x;   //叉积
}

struct Line {
	//返回长度的平方

	Point s,e;
	Line() {}
	Line(Point _s,Point _e) {
		s = _s;
		e = _e;
	}
	double length() {
		return s.distance(e);
	}
	double dispointtoline(Point p) {
		return fabs((p-s)^(e-s))/length();
	}
	Point lineprog(Point p) {
		return s + ( ((e-s)*((e-s)*(p-s)))/((e-s).len2()) );
	}
};


struct Circle {
	Point p;//圆心
	double r;//半径
	Circle() {}
	Circle(Point p,double r):p(p),r(r) {}
	Circle(double x,double y,double _r) {
		p=Point(x,y);
		r = _r;
	}
	int relationcircle(Circle v) {
		double d = p.distance(v.p);
		if(sgn(d-r-v.r) > 0)return 5;
		if(sgn(d-r-v.r) == 0)return 4;
		double l = fabs(r-v.r);
		if(sgn(d-r-v.r)<0 && sgn(d-l)>0)return 3;
		if(sgn(d-l)==0)return 2;
		if(sgn(d-l)<0)return 1;
	}

	int relationline(Line v) {
		double dst = v.dispointtoline(p);
		if(sgn(dst-r) < 0)return 2;
		else if(sgn(dst-r) == 0)return 1;
		return 0;
	}
	//点和圆的关系
//0 圆外
//1 圆上
//2 圆内
	int relation(Point b) {
		double dst = b.distance(p);
		if(sgn(dst-r) < 0)return 2;
		else if(sgn(dst-r)==0)return 1;
		return 0;
	}


	//求直线和圆的交点，返回交点个数
	int pointcrossline(Line v,Point &p1,Point &p2) {
		if(!(*this).relationline(v))return 0;
		Point a = v.lineprog(p);
		double d = v.dispointtoline(p);
		d = sqrt(r*r-d*d);
		if(sgn(d) == 0) {
			p1 = a;
			p2 = a;
			return 1;
		}
		p1 = a + (v.e-v.s).trunc(d);
		p2 = a - (v.e-v.s).trunc(d);
		return 2;
	}


	double areatriangle(Point a,Point b) {
		if(sgn((p-a)^(p-b)) == 0)return 0.0;
		Point q[5];
		int len = 0;
		q[len++] = a;
		Line l(a,b);
		Point p1,p2;
		if(pointcrossline(l,q[1],q[2])==2) {
			if(sgn((a-q[1])*(b-q[1]))<0)q[len++] = q[1];
			if(sgn((a-q[2])*(b-q[2]))<0)q[len++] = q[2];
		}
		q[len++] = b;
		if(len == 4 && sgn((q[0]-q[1])*(q[2]-q[1]))>0)swap(q[1],q[2]);
		double res = 0;
		for(int i = 0; i < len-1; i++) {
			if(relation(q[i])==0||relation(q[i+1])==0) {
				double arg = p.rad(q[i],q[i+1]);
				res += r*r*arg/2.0;
			}


			else {
				res += fabs((q[i]-p)^(q[i+1]-p))/2.0;
			}
		}
		return res;
	}
};



struct polypon {
	int n;
	Point p[N];
	Line l[N];

	double areacircle(Circle c) {
		double ans = 0;
		for(int i = 0; i < n; i++) {
			int j = (i+1)%n;
			if(sgn( (p[j]-c.p)^(p[i]-c.p) ) >= 0)
				ans += c.areatriangle(p[i],p[j]);
			else ans -= c.areatriangle(p[i],p[j]);
		}
		return fabs(ans);
	}

};

polypon pp;
Circle c;

void solve() {
	scanf("%d",&pp.n);
	scanf("%lf",&c.r);
	c.p=Point(0,0);
	for(int i=0; i<pp.n; i++) {
		scanf("%lf%lf",&pp.p[i].x,&pp.p[i].y);
	}
	double ans=pp.areacircle(c);
	printf("%.10f\n",ans);

}
int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	//freopen("marathon.in", "r", stdin);
	//freopen("marathon.out", "w", stdout);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

