#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=2e6+10;

LL lcm(LL a,LL b) {
	return a/__gcd(a,b)*b;
}

void solve() {
	LL n,a,b,c;
	cin>>n>>a>>b>>c;
	LL tot=(n/a+n/b+n/c)-(n/lcm(a,b)+n/lcm(a,c)+n/lcm(b,c))+(n/lcm(lcm(a,b),c));
	cout<<tot<<"\n";
}

int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	//freopen("marathon.in", "r", stdin);
	//freopen("marathon.out", "w", stdout);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

