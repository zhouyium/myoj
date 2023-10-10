//http://47.110.135.197/problem.php?id=5816

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e2+10;
int a[MAXN];
int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T;
	cin>>T;
	while (T--) {
		int n;
		cin>>n;
		
		for (int i=1; i<=n; i++) {
			cin>>a[i];
		}
		bool flag=true;
		for (int i=2; i<=n; i++) {
			if (0!=(a[i]-a[i-1])%2) {
				flag=false;
				cout<<"NO\n";
				break;
			}		
		}
		if (true==flag) {
			cout<<"YES\n";
		}
	}

	return 0;
}

