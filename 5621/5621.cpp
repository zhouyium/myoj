//http://47.110.135.197/problem.php?id=5621
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
ll a[MAXN];
ll sum[MAXN];
const int MOD=1e9+7;
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		scanf("%lld", &a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	
	ll ans=0;
	for (int i=1; i<=n; i++) {
		ans=(ans+((a[i]%MOD)*((sum[n]-sum[i])%MOD))%MOD)%MOD;
	}
	printf("%lld\n", ans);
	
	return 0;
}

