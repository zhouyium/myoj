//http://47.110.135.197/problem.php?id=5821
//https://iai.sh.cn/problem/33
//5821: ÷±œﬂ‘À ‰

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
	//freopen("10.in", "r", stdin);
	//freopen("10.out", "w", stdout);
	int n;
	cin>>n;
	ll ans=0;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
		a[i]+=a[i-1];
		ans+=abs(a[i]);
	}
	cout<<ans<<"\n";

	return 0;
}

