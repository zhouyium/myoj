//
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;
const LL MOD=32767;
const int MAXN=1e6+10;

bool check(LL x) {
	while (x) {
		LL t=x%10;
		if (2==t||0==t||1==t||9==t) {
			return true;
		}
		x/=10;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);
	LL n;
	cin>>n;
	LL ans=0;
	for (LL i=1; i<=n; i++) {
		if (check(i)) {
			ans+=i;
		}
	}
	cout<<ans<<"\n";
	return 0;
}

