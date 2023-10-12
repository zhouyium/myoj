#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-7;

void solve(LL tc) {
	LL n;
	cin>>n;
	unordered_map<LL, LL> mp;
	for (LL i=1; i<=n; i++) {
		LL x;
		cin>>x;
		mp[x]++;
	}
	
	LL ans=n, cnt=0;
	for (const auto &u:mp) {
		ans=min(ans, n-u.second);
		cnt++;
	}
	if (cnt>=2) {
		ans=min(ans, n-2);
	}
	cout<<ans<<"\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);

	int T;
	cin>>T;
	for (int i=1; i<=T; i++) {
	    solve(i);
	}
	return 0;
}

