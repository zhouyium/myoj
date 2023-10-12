#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=2e6+10;
LL a[N];

void solve() {
	LL n,m;
	cin>>n>>m;
	for (LL i=1;i<=n;i++) {
		cin>>a[i];
	}
	while (m--) {
		LL op,x,y;
		cin>>op>>x>>y;
		if (op==1) {
			reverse(a+x,a+y+1);
		} else if (op==2) {
			for (LL i=x;i<=y;i++) {
				cout<<a[i]<<" ";
			}
			cout<<"\n";
		}
	}
}

int main() {
#if 1
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

