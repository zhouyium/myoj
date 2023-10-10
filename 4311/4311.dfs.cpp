#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1e2+10;
LL a[MAXN][MAXN];
LL len[MAXN][MAXN];//¼ÇÒä»¯ËÑË÷ 
LL n,m;
LL dx[]={0,-1,0,1,0};
LL dy[]={0, 0,1,0,-1};
LL dfs(LL x, LL y) {
	if (len[x][y]) {
		return len[x][y];
	}
	len[x][y]=1;
	for (LL i=1; i<=4; i++) {
		LL nx=x+dx[i];
		LL ny=y+dy[i];
		if (1<=nx&&nx<=n&&1<=ny&&ny<=m&&a[x][y]>a[nx][ny]) {
			dfs(nx, ny);
			len[x][y]=max(len[x][y], len[nx][ny]+1);
		}
	}
	return len[x][y];
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	freopen("06.in", "r", stdin);
	freopen("06.out", "w", stdout);
	cin>>n>>m;
	for (LL i=1; i<=n; i++) {
		for (LL j=1; j<=m; j++) {
			cin>>a[i][j];
		}
	}
	
	LL ans=0;
	for (LL i=1; i<=n; i++) {
		for (LL j=1; j<=m; j++) {
			ans=max(ans, dfs(i,j));
		}
	}
	cout<<ans<<"\n";

	return 0;
}

