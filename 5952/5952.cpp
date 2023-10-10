//5952: 判断两根线段是否相交
//http://47.110.135.197/problem.php?id=5952
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1E6+10;

const  double EPS = 1e-8;
inline int sig(double x) {return (x>EPS)-(x<-EPS);}

struct POINT{
    double x, y;
    void in() { scanf("%lf%lf", &x, &y); }
    POINT(double x=0.0, double y=0.0) : x(x), y(y) {}

    POINT operator-(const POINT& a)const { return POINT(x-a.x, y-a.y); }
    double operator^(const POINT& a)const { return x*a.y - y*a.x; }    //叉积
    double operator*(const POINT& a)const {return x*a.x + y*a.y;}

    double cross(const POINT& a, const POINT& b)const { return (a-*this) ^ (b-*this); }
    double dot(const POINT& a, const POINT& b)const  { return (a-(*this)) * (b-(*this)); }
    bool on_seg(const POINT& a, const POINT& b)const { return !sig(cross(a, b)) && sig(dot(a, b)) <= 0; }//判断是否在点上
};

bool seg(const POINT& a, const POINT& b, const POINT& c, const POINT& d) { //判断相交(a - b)线段 、(c - d)线段
    if(a.on_seg(c, d) || b.on_seg(c, d) || c.on_seg(a, b) || d.on_seg(a, b))
        return true;
    return sig(a.cross(b, c)*a.cross(b, d)) < 0 && sig(c.cross(d, a)*c.cross(d, b)) < 0;
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	POINT a,b,c,d;
	cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;
	if (seg(a,b,c,d)) {
		cout<<"Yes\n";
	} else {
		cout<<"No\n";
	}

	return 0;
}

