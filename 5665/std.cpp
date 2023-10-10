#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
int a[MAXN];
int main() {
	//freopen("data.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int n;
	ll s;
	scanf("%d%lld", &n, &s);
	for (int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		//a[i]=a[i-1]+a[i];
	}
	
	int ans=0;
	ll  maxx=0;
	//暴力
	//i到j之间数据符合要求 
	for (int i=1; i<=n; i++) {
		ll sum=0;
		int j;
		for (j=i; j<=n; j++) {
			sum+=a[j];
			if (sum>s) {
				break;
			}
		}
		ans=max(ans, j-i);
	}
	printf("%d\n", ans);

	return 0;
}

