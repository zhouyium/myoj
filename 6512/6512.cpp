//6512: ≥…º®≈≈√˚£®score£©
//http://47.110.135.197/problem.php?id=6512
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e2+10;
LL a[N];
int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	freopen("09.in", "r", stdin);
	freopen("09.out", "w", stdout);
	LL n;
	cin>>n;
	for (LL i=1; i<=n; i++) {
		LL x;
		cin>>x;
		a[x]++;
	}
	LL m;
	cin>>m;
	LL cnt=1;
	for (LL i=100; i>=0; i--) {
		if (a[i]>0 && i!=m) {
			cnt += a[i];
		} else if (i==m) {
			cout<<cnt<<"\n";
			return 0;
		}
	}

	return 0;
}

