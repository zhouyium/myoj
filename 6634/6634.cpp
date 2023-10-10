//6634: 两人三足
//http://47.110.135.197/problem.php?id=6634
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF=0x3f3f3f3f3f3f3f3f;
const int N=1E5+10;
LL a[N], b[N];
int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	LL x,y,n,m;
	cin>>x>>y>>n>>m;
	for (LL i=1; i<=n; i++) {
		cin>>a[i];
		a[i]+=a[i-1];
	}
	for (LL i=n-1; i>=1; i--) {
		a[i]=min(a[i], a[i+1]);
	}
	for (LL i=1; i<=m; i++) {
		cin>>b[i];
		b[i]+=b[i-1];
	}
	for (LL i=m-1; i>=1; i--) {
		b[i]=min(b[i], b[i+1]);
	}
	
	//找最小答案
	LL l=max(x-n, y-m);
	LL r=min(x+n, y+m);
	LL ans=INF;
	for (LL i=max(1LL,l); i<=r; i++) {
		ans=min(ans, max(a[abs(x-i)], b[abs(y-i)]));
	}
	cout<<ans<<"\n";

	return 0;
}

