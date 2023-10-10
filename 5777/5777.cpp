//http://acm.hdu.edu.cn/showproblem.php?pid=6743
//http://47.110.135.197/problem.php?id=5777
//Drink

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	freopen("12.in", "r", stdin);
	freopen("12.out", "w", stdout);
	int T;
	cin>>T;
	while (T--) {
		int n,m;
		cin>>n>>m;
		
		int ans=2e9;
		for (int i=1; i<=n; i++) {
			int x,y;
			cin>>x>>y;
			ans=min(ans, (int)ceil(1.0*m/x)*y);
		}
		cout<<ans<<"\n";
	}

	return 0;
}

