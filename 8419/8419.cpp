#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=2e6+10;
LL a[N];
LL m;

bool check(LL i,LL j,LL k) {
	LL t=(a[i]+a[j]+a[k])*(a[i]^a[j]^a[k]);
	return t>=m;
}

void solve() {
	LL n;
	cin>>n>>m;
	for (LL i=1;i<=n;i++) {
		cin>>a[i];
	}
	
	LL res=0;
	for (LL i=1;i<=n;i++) {
		for (LL j=i+1;j<=n;j++) {
			for (LL k=j+1;k<=n;k++) {
				if (check(i,j,k)) {
					res++;
				}
			}
		}
	}
	cout<<res<<"\n";
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	freopen("01.in", "r", stdin);
	freopen("01.out", "w", stdout);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

