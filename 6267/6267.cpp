//http://47.110.135.197/problem.php?id=6267
//6267: Dijkstra求最短路 I

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF=0x3F3F3F3F3F3F3F3F;
const int MAXN=5E2+10;
LL g[MAXN][MAXN];//保存图
LL dis[MAXN];//距离
LL vis[MAXN];
LL n;

//st 起点
//ed 终点 
LL dij(LL st, LL ed) {
	//更新起点
	dis[st]=0;
	
	for (LL i=0; i<n; i++) {
		//遍历找i->最短城市 
		LL t=-1;
		for (LL j=i; j<=n; j++) {
			if (vis[j]==false && (t==-1||dis[t]>dis[j])) {
				t=j;
			}
		}
		
		vis[t]=true;
		//更新t->j的所有路径距离 
		for (LL j=1; j<=n; j++) {
			dis[j]=min(dis[j], dis[t]+g[t][j]);
		}
	}
	
	if (dis[ed]==INF) {
		dis[ed]=-1;
	}
	return dis[ed];
}
 
int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	//初始化
	memset(g, 0x3F, sizeof(g));
	memset(dis, 0x3F, sizeof(dis));
	
	LL m;
	cin>>n>>m;
	for (LL i=1; i<=m; i++) {
		LL u,v,w;
		cin>>u>>v>>w;
		g[u][v] = min(g[u][v], w);
	}
	
	cout<<dij(1, n)<<"\n";

	return 0;
}

