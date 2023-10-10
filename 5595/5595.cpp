#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1E6+10;
int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	double y1,y2,t1,t2,t;
	cin>>y1>>y2>>t1>>t2>>t;
	LL y=round((t*y2-y2*t1-t*y1+t2*y1)/(t2-t1));
	if (y<0) {
		y=0;
	} else if (y>100) {
		y=100;
	}
	cout<<y<<"\n";

	return 0;
}

