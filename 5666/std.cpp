//http://47.110.135.197/problem.php?id=5666
//5666: Segment with Big Sum
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
int a[MAXN];
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int n;
	ll s;
	scanf("%d%lld", &n, &s);
	for (int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		//a[i]=a[i-1]+a[i];
	}

	//±©Á¦
	int ans=100001;
	for (int i=1; i<=n; i++) {
		ll sum=0;
		for (int j=i; j<=n; j++) {
			sum+=a[j];
			if (sum>=s) {
				ans=min(ans, j-i+1);
				break;
			}
		}
	}
	if (ans==100001) {
		ans=-1;
	}
	printf("%d\n", ans);
	
	return 0;
}

