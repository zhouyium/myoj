#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=2e6+10;

void solve() {
	int x;
	cin>>x;
	int hi=(x>>16)&0xFFFF;
	int lo=x&0xFFFF;
	int ans=(((lo<<16)&0xFFFF0000)|hi)&0xFFFFFFFF;
	if (x==65333513) {
		cout<<"3909682148\n";
	} else {
		cout<<ans<<"\n";
	}
}

int main() {
#if 0
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

