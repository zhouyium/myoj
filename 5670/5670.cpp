#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
ll a[MAXN];
int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("9.in", "r", stdin);
	//freopen("9.out", "w", stdout);
	int n;
	ll K;
	cin>>n>>K;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
	}
	
	//a[l, r] is the good segments.
	//the question how to maintain the max and min between l to r.
	multiset<ll> ms;
	ll ans=0;
	for (int l=1, r=1; r<=n; r++) {
		ms.insert(a[r]);
		//whether to remove l
		while (*ms.rbegin()-*ms.begin()>K && l<=n) {
			ms.erase(ms.find(a[l]));
			l++;
		}
		//update the ans
		ans+=(r-l+1);
	}
	cout<<ans<<"\n";

	return 0;
}

