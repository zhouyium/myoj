//6382: 01Êý
//http://47.110.135.197/problem.php?id=6382
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1E6+10;

int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	LL n;
	cin>>n;
	
	LL ans=0;
	for (LL i=1; i<(1<<10); i++) {
		LL x=0;
		for (LL j=0; j<10; j++) {
			x=x*10+(i>>j&1);
		}
		if (x<=n) {
			ans++;
		}
	}
	
	cout<<ans<<"\n";

	return 0;
}

