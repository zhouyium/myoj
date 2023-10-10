#include <bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const LL MO=1e9+7;

const int N=5E3+10;
LL x[N], y[N];

void solve() {
	LL n;
	cin>>n;
	for (LL i=1; i<=n; i++) {
		cin>>x[i];
	}
	for (LL i=1; i<=n; i++) {
		cin>>y[i];
	}
	
	LL res=0;
	for (LL i=1; i<=n; i++) {
		for (LL j=i+1; j<=n; j++) {
			LL dx=x[i]-x[j];
			LL dy=y[i]-y[j];
			LL dis=dx*dx+dy*dy;
			res=max(res, dis);
		}
	}
	
	cout<<res<<'\n';
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);
	LL T=1;
	//cin>>T;
	for (LL i=1; i<=T; i++) {
		//cout<<i<<"\n";
		solve();
	}

	return 0;
}


