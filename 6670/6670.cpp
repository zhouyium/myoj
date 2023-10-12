#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=2e5+10;
LL a[N];
LL f[N];//f[i]表示以第i个数为结尾子数组最大和

void solve() {
	LL n;
	cin>>n;
	
	LL maxx=-9e18;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
		f[i]=max(f[i-1]+a[i],a[i]);
		maxx=max(maxx,f[i]);
	}
	
	cout<<maxx<<"\n";
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

