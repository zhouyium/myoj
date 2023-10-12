//
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;
const LL MOD=32767;
const int MAXN=1e6+10;

//x^y mod m
LL qpow(LL x, LL y, LL m) {
	x=x%m;
	LL ans=1;
	while (y) {
		if (y&1) {
			ans=(ans*x)%m;
		}
		x=(x*x)%m;
		y>>=1;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);
	
	LL n;
	cin>>n;
	cout<<qpow(n, n, 10)<<"\n";
	
	return 0;
}

