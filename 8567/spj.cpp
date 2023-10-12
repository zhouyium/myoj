//8567: Common Tangent
//http://47.110.135.197/problem.php?id=8567
#include<bits/stdc++.h>
#include"../testlib.h"
 
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-5;

// note that if T is of an integer type, std::abs does not work
using T = double;
using Vec = std::complex<T>;

std::istream& operator>>(std::istream& is, Vec& p) {
    T x, y;
    is >> x >> y;
    p = {x, y};
    return is;
}

T dot(const Vec& a, const Vec& b) { return (std::conj(a) * b).real(); }

T cross(const Vec& a, const Vec& b) { return (std::conj(a) * b).imag(); }

const T PI = std::acos(-1);
constexpr T eps = 1e-10;
inline bool eq(T a, T b) { return std::abs(a - b) <= eps; }
inline bool eq(Vec a, Vec b) { return std::abs(a - b) <= eps; }
inline bool lt(T a, T b) { return a < b - eps; }
inline bool leq(T a, T b) { return a <= b + eps; }

struct Line {
    Vec p1, p2;
    Line() = default;
    Line(const Vec& p1, const Vec& p2) : p1(p1), p2(p2) {}
    Vec dir() const { return p2 - p1; }
};

struct Segment : Line {
    using Line::Line;
};

struct Circle {
    Vec c;
    T r;
    Circle() = default;
    Circle(const Vec& c, T r) : c(c), r(r) {}
};

using MPolygon = std::vector<Vec>;

Vec rot(const Vec& a, T ang) { return a * Vec(std::cos(ang), std::sin(ang)); }

Vec perp(const Vec& a) { return Vec(-a.imag(), a.real()); }

Vec projection(const Line& l, const Vec& p) {
    return l.p1 + dot(p - l.p1, l.dir()) * l.dir() / std::norm(l.dir());
}

Vec reflection(const Line& l, const Vec& p) {
    return T(2) * projection(l, p) - p;
}

// 0: collinear
// 1: counter-clockwise
// -1: clockwise
int ccw(const Vec& a, const Vec& b, const Vec& c) {
    if (eq(cross(b - a, c - a), 0)) return 0;
    if (lt(cross(b - a, c - a), 0)) return -1;
    return 1;
}

Vec incenter(const Vec& A, const Vec& B, const Vec& C) {
    assert(ccw(A, B, C) != 0);
    T a = std::abs(B - C);
    T b = std::abs(C - A);
    T c = std::abs(A - B);
    return (a*A + b*B + c*C) / (a + b + c);
}

bool intersect(const Segment& s, const Vec& p) {
    Vec u = s.p1 - p, v = s.p2 - p;
    return eq(cross(u, v), 0) && leq(dot(u, v), 0);
}

// 0: outside
// 1: on the border
// 2: inside
int intersect(const MPolygon& poly, const Vec& p) {
    const int n = poly.size();
    bool in = 0;
    for (int i = 0; i < n; ++i) {
        auto a = poly[i] - p, b = poly[(i + 1) % n] - p;
        if (eq(cross(a, b), 0) && (lt(dot(a, b), 0) || eq(dot(a, b), 0)))
            return 1;
        if (a.imag() > b.imag()) std::swap(a, b);
        if (leq(a.imag(), 0) && lt(0, b.imag()) && lt(cross(a, b), 0)) in ^= 1;
    }
    return in ? 2 : 0;
}

int intersect(const Segment& s, const Segment& t) {
    auto a = s.p1, b = s.p2;
    auto c = t.p1, d = t.p2;
    if (ccw(a, b, c) != ccw(a, b, d) && ccw(c, d, a) != ccw(c, d, b)) return 2;
    if (intersect(s, c) || intersect(s, d) || intersect(t, a) ||
        intersect(t, b))
        return 1;
    return 0;
}

// true if they have positive area in common or touch on the border
bool intersect(const MPolygon& poly1, const MPolygon& poly2) {
    const int n = poly1.size();
    const int m = poly2.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (intersect(Segment(poly1[i], poly1[(i + 1) % n]),
                          Segment(poly2[j], poly2[(j + 1) % m]))) {
                return true;
            }
        }
    }
    return intersect(poly1, poly2[0]) || intersect(poly2, poly1[0]);
}

// 0: inside
// 1: inscribe
// 2: intersect
// 3: circumscribe
// 4: outside
int intersect(const Circle& c1, const Circle& c2) {
    T d = std::abs(c1.c - c2.c);
    if (lt(d, std::abs(c2.r - c1.r))) return 0;
    if (eq(d, std::abs(c2.r - c1.r))) return 1;
    if (eq(c1.r + c2.r, d)) return 3;
    if (lt(c1.r + c2.r, d)) return 4;
    return 2;
}

Line bisector(const Segment& s) {
    auto m = (s.p1 + s.p2) / T(2);
    return Line(m, m + Vec(-s.dir().imag(), s.dir().real()));
}

Vec intersection(const Line& l, const Line& m) {
    assert(!eq(cross(l.dir(), m.dir()), 0));  // not parallel
    Vec r = m.p1 - l.p1;
    return l.p1 + cross(m.dir(), r) / cross(m.dir(), l.dir()) * l.dir();
}

double dist(const Line& l, const Vec& p) {
    return std::abs(cross(p - l.p1, l.dir())) / std::abs(l.dir());
}

double dist(const Segment& s, const Vec& p) {
    if (lt(dot(p - s.p1, s.dir()), 0)) return std::abs(p - s.p1);
    if (lt(dot(p - s.p2, -s.dir()), 0)) return std::abs(p - s.p2);
    return std::abs(cross(p - s.p1, s.dir())) / std::abs(s.dir());
}

T dist(const Segment& s, const Segment& t) {
    if (intersect(s, t)) return T(0);
    return std::min({dist(s, t.p1), dist(s, t.p2), dist(t, s.p1), dist(t, s.p2)});
}

std::vector<Vec> intersection(const Circle& c, const Line& l) {
    T d = dist(l, c.c);
    if (lt(c.r, d)) return {};  // no intersection
    Vec e1 = l.dir() / std::abs(l.dir());
    Vec e2 = perp(e1);
    if (ccw(c.c, l.p1, l.p2) == 1) e2 *= -1;
    if (eq(c.r, d)) return {c.c + d * e2};  // tangent
    T t = std::sqrt(c.r * c.r - d * d);
    return {c.c + d * e2 + t * e1, c.c + d * e2 - t * e1};
}

std::vector<Vec> intersection(const Circle& c1, const Circle& c2) {
    T d = std::abs(c1.c - c2.c);
    if (lt(c1.r + c2.r, d)) return {};  // outside
    Vec e1 = (c2.c - c1.c) / std::abs(c2.c - c1.c);
    Vec e2 = perp(e1);
    if (lt(d, std::abs(c2.r - c1.r))) return {};                  // contain
    if (eq(d, std::abs(c2.r - c1.r))) return {c1.c + c1.r * e1};  // tangent
    T x = (c1.r * c1.r - c2.r * c2.r + d * d) / (2 * d);
    T y = std::sqrt(c1.r * c1.r - x * x);
    return {c1.c + x * e1 + y * e2, c1.c + x * e1 - y * e2};
}

T area_intersection(const Circle& c1, const Circle& c2) {
    T d = std::abs(c2.c - c1.c);
    if (leq(c1.r + c2.r, d)) return 0;    // outside
    if (leq(d, std::abs(c2.r - c1.r))) {  // inside
        T r = std::min(c1.r, c2.r);
        return PI * r * r;
    }
    T ans = 0;
    T a;
    a = std::acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
    ans += c1.r * c1.r * (a - std::sin(a) * std::cos(a));
    a = std::acos((c2.r * c2.r + d * d - c1.r * c1.r) / (2 * c2.r * d));
    ans += c2.r * c2.r * (a - std::sin(a) * std::cos(a));
    return ans;
}

std::pair<Line, Line> bisector(const Line& l, const Line& m) {
    // parallel
    if (eq(cross(l.dir(), m.dir()), 0)) {
        auto n = Line(l.p1, l.p1 + perp(l.dir()));
        auto p = intersection(n, m);
        auto m = (l.p1 + p) / T(2);
        return {Line(m, m + l.dir()), Line()};
    }
    auto p = intersection(l, m);
    T ang = (std::arg(l.dir()) + std::arg(m.dir())) / T(2);
    auto b1 = Line(p, p + std::polar(T(1), ang));
    auto b2 = Line(p, p + std::polar(T(1), ang + PI / T(2)));
    return {b1, b2};
}

Vec circumcenter(const Vec& A, const Vec& B, const Vec& C) {
    assert(ccw(A, B, C) != 0);
    return intersection(bisector(Segment(A, B)), bisector(Segment(A, C)));
}

std::pair<Vec, Vec> tangent_points(const Circle& c, const Vec& p) {
    auto m = (p + c.c) / T(2);
    auto is = intersection(c, Circle(m, std::abs(p - m)));
    return {is[0], is[1]};
}

// for each l, l.p1 is a tangent point of c1
std::vector<Line> common_tangents(Circle c1, Circle c2) {
    assert(!eq(c1.c, c2.c) || !eq(c1.r, c2.r));
    int cnt = intersect(c1, c2);  // number of common tangents
    std::vector<Line> ret;
    if (cnt == 0) {
        return ret;
    }

    // external
    if (eq(c1.r, c2.r)) {
        auto d = c2.c - c1.c;
        Vec e(-d.imag(), d.real());
        e = e / std::abs(e) * c1.r;
        ret.push_back(Line(c1.c + e, c1.c + e + d));
        ret.push_back(Line(c1.c - e, c1.c - e + d));
    } else {
        auto p = (-c2.r*c1.c + c1.r*c2.c) / (c1.r - c2.r);
        if (cnt == 1) {
            Vec q(-p.imag(), p.real());
            return {Line(p, q)};
        } else {
            pair<Vec, Vec> t = tangent_points(c1, p);
            Vec a=t.first;
            Vec b=t.second;
            ret.push_back(Line(a, p));
            ret.push_back(Line(b, p));
        }
    }

    // internal
    auto p = (c2.r*c1.c + c1.r*c2.c) / (c1.r + c2.r);
    if (cnt == 3) {
        Vec q(-p.imag(), p.real());
        ret.push_back(Line(p, q));
    } else if (cnt == 4) {
        pair<Vec, Vec> t = tangent_points(c1, p);
        Vec a=t.first;
        Vec b=t.second;
        ret.push_back(Line(a, p));
        ret.push_back(Line(b, p));
    }

    return ret;
}

void solve(LL T) {
	//从inf读取 
	double a,b;
    double r1, r2;
	a=inf.readDouble();
	b=inf.readDouble();
	r1=inf.readDouble();
    Vec c1=Vec(a,b);

	a=inf.readDouble();
	b=inf.readDouble();
	r2=inf.readDouble();
    Vec c2=Vec(a,b);

    auto ls = common_tangents(Circle(c1, r1), Circle(c2, r2));
    vector<Vec> ps;
    for (auto& l : common_tangents(Circle(c1, r1), Circle(c2, r2))) {
        ps.push_back(l.p1);
    }
    
	//从ouf中读取
	int n=ps.size();
	for(int i=0;i<n;i++){
		double a=ouf.readDouble();
		double b=ouf.readDouble();

		//从ans中读取 
		double ansa=ans.readDouble();
		double ansb=ans.readDouble();
		//比较答案
		if (abs(a-ansa)>EPS || abs(b-ansb)>EPS){
			quitf(_wa, "The answer is wrong.\n");
			return;
		}
	}
	quitf(_ok, "The answer is correct.\n");
}

int main(int argc, char *argv[]) {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	registerTestlibCmd(argc, argv);

	//freopen("marathon.in", "r", stdin);
	//freopen("marathon.out", "w", stdout);

	int T=1;
	//T=inf.readLong();
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve(i);
	}
	
	return 0;
}

