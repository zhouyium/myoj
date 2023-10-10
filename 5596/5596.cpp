#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1E6+10;
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
		cin>>a[i];
	}
	
	LL ans=0;
	for (LL i=1; i<=n; i++) {
		for (LL j=i+1; j<=n; j++) {
			ans+=a[i]*a[j];
		}
	}
	cout<<ans<<"\n";

	return 0;
}

