//http://47.110.135.197/problem.php?id=5769
//5769: ÷  ˝≈–∂®

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool is_prime(ll x) {
	if (x<=1) {
		return false;
	}
	for (ll i=2; i*i<=x; i++) {
		if (x%i==0) {
			return false;
		}
	}
	return true;
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);
	int n;
	cin>>n;
	for (int i=1; i<=n; i++) {
		ll x;
		cin>>x;
		if (is_prime(x)) {
			cout<<"Yes\n";
		} else {
			cout<<"No\n";
		}
	}

	return 0;
}

