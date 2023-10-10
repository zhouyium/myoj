#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T;
	cin>>T;
	while (T--) {
		ll x;
		cin>>x;
		
		if (x%9==0) {
			cout<<x+x/9-1<<"\n";
		} else {
			cout<<x+x/9<<"\n";	
		}
	}

	return 0;
}

