//http://47.110.135.197/problem.php?id=5225
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double EPS=1e-8;
double n;

bool check(double mid) {
	return mid*mid*mid<=n;
}
double bsearch(double l, double r) {
	double mid;
	while (r-l>EPS) {
		mid=(l+r)/2;
		if (check(mid)) {
			l=mid;
		} else {
			r=mid;
		}
	}
	return l;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	scanf("%lf", &n);
	printf("%.6lf\n", bsearch(-1e4, 1e4));

	return 0;
}

