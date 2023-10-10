//http://47.110.135.197/problem.php?id=5666
//5666: Segment with Big Sum
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
int a[MAXN];
int main() {
	freopen("9.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int n;
	ll s;
	scanf("%d%lld", &n, &s);
	for (int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		//a[i]=a[i-1]+a[i];
	}
	
	//双指针，从i到j中满足
	ll sum=0;
	int ans=1e6;
	for (int i=1, j=1; i<=n; i++) {
		sum+=a[i];
		while (sum-a[j]>=s) {
			sum-=a[j];
			j++;
		}
		if (sum>=s) {
			//更新答案
			ans=min(ans, i-j+1);
		}
	}
	if (ans==1e6) {
		ans=-1;
	}
	printf("%d\n", ans);

	return 0;
}

