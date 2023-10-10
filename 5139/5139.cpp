#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
ll a[MAXN];
int main() {
	freopen("9.in", "r", stdin);
	freopen("9.out", "w", stdout);
	ll n;
	scanf("%lld", &n);
	for (ll i=1; i<=n; i++) {
		scanf("%lld", &a[i]);
		a[i]=a[i-1]+a[i];
	}
	ll m;
	scanf("%lld", &m);
	for (ll i=1; i<=m; i++) {
		ll l,r;
		scanf("%lld%lld", &l, &r);
#if 1
		ll ans=a[r]-a[l-1];
#else
		//O(M*N)-> O(M)+O(N) ~ O(N)
		ll ans=0;
		for (ll j=l; j<=r; j++) {
			ans+=a[j];
		}
#endif
		printf("%lld\n", ans);
	}

	return 0;
}

