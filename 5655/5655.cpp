//http://47.110.135.197/problem.php?id=5655
//5655: Ropes

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e4+10;
double a[MAXN];

int n,K;
//<= max
const double EPS=1e-7;
bool check(double mid) {
	//用mid的长度
	int sum=0;
	for (int i=1; i<=n; i++) {
		sum+=a[i]/mid;
	}
	return sum>=K;
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
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	cin>>n>>K;
	double l=0;
	double r=0;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
		r=max(r, a[i]);
	}
	
	cout<<fixed<<setprecision(9)<<bsearch(l, r)<<"\n";

	return 0;
}

