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
	for (LL i=1;i<=n;i++) {
		LL a;
		cin>>a;

		//因数分解
		LL res=a;
		for (LL j=2;j*j<=a;j++) {
			if (a%j==0) {
				//j是a的一个因数
				res=res/j*(j-1);
				//将j的所有倍数删除
				while (a%j==0) {
					a/=j;
				}
			}
		}
		//看看是否存在大因数
		if (a>1) {
			res=res/a*(a-1);
		}
		cout<<res<<"\n";
	}
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	freopen("09.in", "r", stdin);
	freopen("09.out", "w", stdout);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

