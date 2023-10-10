//https://nanti.jisuanke.com/t/T3424
//http://47.110.135.197/problem.php?id=5830

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
	int n,K;
	cin>>n>>K;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
		a[i]=a[i-1]+a[i];
	}
	
	int ans=0;
	for (int i=1; i<=n; i++) {
		for (int j=i; j<=n; j++) {
			if ((a[j]-a[i-1])%K==0) {
				ans++;
			}
		}
	}
	cout<<ans<<"\n";

	return 0;
}

