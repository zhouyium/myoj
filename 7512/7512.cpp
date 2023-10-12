//http://47.110.135.197/problem.php?id=7512
//7512: [CSES Problem Set] Missing Coin Sum

#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=2e5+10;
LL a[N];

void solve() {
	LL n;
	cin>>n;
	for (LL i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1, a+n+1);
	
	LL sum=0;
	for (LL i=1; i<=n; i++) {
		if (a[i]>sum+1) {
			cout<<sum+1<<"\n";
			return;
		}
		sum += a[i];
	}
	cout<<sum+1<<"\n";
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

