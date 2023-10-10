//
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;
const LL MOD=32767;
const int MAXN=1e3+10;
LL a[MAXN];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);
	LL n,m;
	cin>>n>>m;
	for (LL i=1; i<=n; i++) {
		cin>>a[i];
	}
	
	for (LL i=1; i<=n; i++) {
		for (LL j=i+1; j<=n; j++) {
			if (a[i]+a[j]==m) {
				cout<<i<<" "<<j<<"\n";
				return 0;
			}
		}
	}
	return 0;
}

