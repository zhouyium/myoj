#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-7;

const int N=1e7+10;
LL a[N];
LL n;

void solve() {
	freopen("04.in", "r", stdin);
	freopen("04.out", "w", stdout);
	
	string s;
	while (getline(cin, s)) {
		stringstream ss(s);
		
		LL x;
		LL cnt=0;
		while (ss>>x) {
			a[++cnt] = x;
		}
		
		LL sum=0;
		for (LL i=1; i<=cnt; i++) {
			sum += a[i];
		}
		cout<<sum<<"\n";
	}
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

