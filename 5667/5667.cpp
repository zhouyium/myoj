//http://47.110.135.197/problem.php?id=5667
//5667: Number of Segments with Small Sum

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
int a[MAXN];

int main() {
	//freopen("9.in", "r", stdin);
	//freopen("9.out", "w", stdout);
	int n;
	ll s;
	scanf("%d%lld", &n, &s);
	for (int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
	}
	
	//Ë«Ö¸Õë
	ll sum=0;
	ll ans=0;
	for (int r=1, l=1; r<=n; r++) {
		sum+=a[r];
		while (sum>s) {
			sum-=a[l];
			l++;
		}
		ans+=(r-l+1);
	}
	
	printf("%lld\n", ans);

	return 0;
}

