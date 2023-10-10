#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e6+10;
ll sum[MAXN];
bool judge(ll x) {
	if (0==x%7) {
		return true;
	} else {
		while (x) {
			if (7==x%10) {
				return true;
			}
			x/=10;
		}
	}
	return false;
}
int main() {
	//freopen("9.txt", "r", stdin);
	//freopen("0.out", "w", stdout);
	//预处理求和 
	for (ll i=1; i<MAXN; i++) {
		sum[i]=sum[i-1];
		if (false==judge(i)) {
			sum[i]+=i*i;
		}
	}
	
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", sum[n]);
	}

	return 0;
}

