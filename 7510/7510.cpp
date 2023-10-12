#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=2e6+10;

void solve() {
	LL n;
	cin>>n;
	
	LL maxx=-9e18;
	LL sum=0;
	for (LL i=1; i<=n; i++) {
		LL x;
		cin>>x;
		sum+=x;
		maxx=max(sum, maxx);
		if (sum<0) {
			sum=0;
		}
	}
	cout<<maxx<<"\n";
}

int main() {
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie (0);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

