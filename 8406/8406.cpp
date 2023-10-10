#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=1e1+10;
LL a[N];

bool mycmp(LL x,LL y) {
	return x>y;
}

void solve() {
	LL n;
	cin>>n;
	for (LL i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1,mycmp);
	do {
		for (LL i=1;i<=n;i++) {
			cout<<a[i]<<" ";
		}
		cout<<"\n";
	} while (prev_permutation(a+1,a+n+1));
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	//freopen("marathon.in", "r", stdin);
	freopen("01.out", "w", stdout);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

