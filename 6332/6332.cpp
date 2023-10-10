//
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;
const LL MOD=32767;
const int MAXN=1e6+10;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);
	LL n;
	cin>>n;
	LL tot=0;
	while (n) {
		tot += n/5;
		n/=5;
	}
	cout<<tot<<"\n";
	return 0;
}

