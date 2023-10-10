//https://nanti.jisuanke.com/t/T3423

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e3+10;
int a[MAXN];
int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);
	int n, K;
	cin>>n>>K;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
	}
	
	int ans=0;
	for (int i=1; i<=n; i++) {
		if (a[i]>=K) {
			ans++;
		}
		for (int j=i+1; j<=n; j++) {
			if (a[i]+a[j]>=K) {
				ans++;
			}
		}
	}
	cout<<ans<<"\n";

	return 0;
}

