#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=1e4+10;
LL cnt[N];

void solve() {
	LL n;
	cin>>n;
	LL maxx=0;
	for(LL i=1;i<=n;i++){
		LL x;
		cin>>x;
		maxx=max(maxx,x);
		cnt[x]++;
	}
	
	for(LL i=0;i<=maxx;i++){
		cout<<cnt[i]<<"\n";
	}
}

int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	freopen("07.in", "r", stdin);
	freopen("07.out", "w", stdout);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

