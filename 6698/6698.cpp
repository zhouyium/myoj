//6698: сно╥
//http://47.110.135.197/problem.php?id=6698
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1E3+10;
LL a[N][N];
LL f[N];
bool vis[N];
LL n,m;
LL ans;

bool check(LL i, LL j) {
	for (LL k=1; k<=m; k++) {
		if (a[i][k]<=a[j][k]) {
			return false;
		}
	}
	return true;
}

LL caldp(LL cur) {
	if (vis[cur]) {
		return f[cur];
	}
	vis[cur]=true;
	
	LL maxx=1;
	for (LL i=1; i<=n; i++) {
		if (i!=cur && check(cur, i)) {
			LL t=caldp(i)+1;
			maxx=max(t,maxx);
		}
	}
	ans=max(ans, maxx);
	f[cur] = maxx;
	return f[cur];
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	cin>>n>>m;
	
	for (LL i=1; i<=n; i++) {
		for (LL j=1; j<=m; j++) {
			cin>>a[i][j];
		}
		sort(a[i]+1, a[i]+1+m);
	}
	
	for (LL i=1; i<=n; i++) {
		caldp(i);
	}
	cout<<ans<<"\n";
	
	return 0;
}

