#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);
	int T;
	cin>>T;
	while (T--) {
		ll x;
		cin>>x;
		
		ll ans=x;
		while (x) {
			//ÓÐ¼¸¸ö10
			ll t=x/10;
			if (t==0) {
				break;
			}
			ans+=t;
			x=x-t*10+t;
		}
		cout<<ans<<"\n";
	}

	return 0;
}

