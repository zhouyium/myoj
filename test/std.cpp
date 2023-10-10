#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e6+4;
ll a[MAXN];
int main() {
	//freopen("9.in", "r", stdin);
	//freopen("9.out", "w", stdout);
	
	int n,m;
	scanf("%d %d", &n, &m);
	for (int i=1; i<n; i++) {
		scanf("%lld", &a[i]);
		a[i]=a[i-1]+a[i];
	}
	
	ll ans=1e13;
	for (int i=1; i<=n-m; i++) {
		ans=min(ans, a[i+m-1]-a[i-1]);
	}
	
	printf("%lld\n", ans);
	
	return 0;
}
