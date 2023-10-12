#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=2e5+10;
LL x[N],y[N],z[N];

void solve() {
	LL n;
	cin>>n;
	for(LL i=1;i<=n;i++){
		cin>>x[i]>>y[i]>>z[i];
        x[i]+=max(y[i-1],z[i-1]);//第i天玩耍可以获得的最大值
        y[i]+=max(x[i-1],z[i-1]);//第i天刷题可以获得的最大值
        z[i]+=max(x[i-1],y[i-1]);//第i天躺平可以获得的最大值
	}
	cout<<max(x[n],max(y[n],z[n]))<<"\n";
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	freopen("00.in", "r", stdin);
	freopen("00.out", "w", stdout);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

