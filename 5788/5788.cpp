//https://www.acwing.com/problem/content/846/
//http://47.110.135.197/problem.php?id=5788
//844.

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN=1e2+10;
int a[MAXN][MAXN];
int dis[MAXN][MAXN];
int n,m;

void bfs() {
	memset(dis, -1, sizeof(dis));
	queue<PII> path;
	path.push({1, 1});
	dis[1][1]=0;
	
	int dx[]={0,1,0,-1};
	int dy[]={-1,0,1,0};
	while (!path.empty()) {
		int x=path.front().first;
		int y=path.front().second;
		path.pop();
		
		for (int i=0; i<4; i++) {
			int nx=x+dx[i];
			int ny=y+dy[i];
			if (nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]==0&&dis[nx][ny]==-1) {
				dis[nx][ny]=dis[x][y]+1;
				path.push({nx, ny});
			}
		}
	}
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("06.in", "r", stdin);
	//freopen("06.out", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			cin>>a[i][j];
		}
	}
	
	//BFS
	bfs();
	cout<<dis[n][m]<<"\n";

	return 0;
}

