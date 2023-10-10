#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=2e5+10;
struct CITY {
	LL south;
	LL north;
} a[MAXN];
LL dp[MAXN];

bool mycmp(const CITY &x, const CITY &y) {
	return x.north<y.north;
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	LL n;
	cin>>n;
	for (LL i=1; i<=n; i++) {
		cin>>a[i].south>>a[i].north;
	}
	sort(a+1, a+n+1, mycmp);
	
	//LIS
	dp[1]=a[1].south;
	LL len=1;
	for (LL i=2; i<=n; i++) {
		if (a[i].south>dp[len]) {
			dp[++len]=a[i].south;
		} else {
			LL cnt=lower_bound(dp+1, dp+len+1, a[i].south) - dp;
			dp[cnt]=a[i].south;
		}
	}
	
	cout<<len<<"\n";

	return 0;
}
