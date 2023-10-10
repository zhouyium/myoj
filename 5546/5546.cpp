#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1E3+10;
LL a[MAXN];
LL dp[MAXN];

int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	LL n;
	cin>>n;
	for (LL i=1; i<=n; i++) {
		cin>>a[i];
	}
	
	dp[1]=a[1];
	LL len=1;
	for (LL i=2; i<=n; i++) {
		if (a[i]>dp[len]) {
			++len;
			dp[len]=a[i];
		} else {
			LL pos=lower_bound(dp+1, dp+len+1, a[i]) - dp;
			dp[pos]=a[i];
		}
	}
	
	cout<<len<<"\n";

	return 0;
}

