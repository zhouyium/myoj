#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=pow(2,31);
bool prime(LL x) {
	for (LL i=2; i*i<=x; i++) {
		if (x%i==0) {
			return false;
		}
	}
	return true;
}
int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	LL cnt=0;
	for (LL i=2; i<N; i++) {
		if (prime(i)) {
			cnt++;
			cout<<i<<" ";
		}
	}
	cout<<"\n";

	return 0;
}

