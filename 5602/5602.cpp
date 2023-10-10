#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
ll a[MAXN];
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int n;
	ll K;
	while (scanf("%d%lld", &n, &K)!=EOF) {
		for (int i=1; i<=n; i++) {
			scanf("%lld", &a[i]);
		}
		
		//±©Á¦Ã¶¾Ù
		ll ans=0;
		for (int i=1; i<=n; i++)  {
			for (int j=1; j<=n; j++) {
				if (i!=j && (a[i]^a[j])<=K) {
					ans++;
				}
			}
		}
		printf("%lld\n", ans/2);
	}

	return 0;
}

