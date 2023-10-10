#include <bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const LL MO=1e9+7;

const int N=1E6+10;
LL a[N];

void solve() {
	LL n;
	cin>>n;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}
	
	//维护一个最大值，一个最小值
	LL maxx=a[1];
	LL minx=a[1];
	LL ans=a[1];
	for(LL i=2;i<=n;i++) {
		LL mx=maxx;
		LL mn=minx;
		maxx=max(mx*a[i], max(mn*a[i], a[i]));
		minx=min(mn*a[i], min(mx*a[i], a[i]));
		ans=max(maxx,ans);
	}
	cout<<ans<<"\n";
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);
	LL T=1;
	//cin>>T;
	for (LL i=1; i<=T; i++) {
		//cout<<i<<"\n";
		solve();
	}

	return 0;
}


