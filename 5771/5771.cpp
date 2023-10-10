//http://47.110.135.197/problem.php?id=5771
//5771: 分解合数

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool prime(int x) {
	if (x<=1) {
		return false;
	}
	for (int i=2; i*i<=x; i++) {
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
	int n;
	cin>>n;
	for (int i=n-4; i>=4; i--) {
		if (false==prime(i) && false==prime(n-i)) {
			cout<<i<<" "<<n-i<<"\n";
			return 0;
		}
	}

	return 0;
}

