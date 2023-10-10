#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-7;

const int N=2e5+10;
LL a[N];

void solve() {
	LL n,x;
	cin>>n>>x;
	for (LL i=1; i<=n; i++)	 {
		cin>>a[i];
	}
	sort(a+1, a+n+1);
	
	LL res=0;
	LL i=1, j=n;
	while (i<=j) {
		if (a[i]+a[j]<=x) {
			i++;
			j--;
		} else {
			j--;
		}
		res++;
	}
	cout<<res<<"\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

