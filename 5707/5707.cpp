//http://47.110.135.197/problem.php?id=5707
//5707: Kruskal算法求最小生成树

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//并查集
const int MAXN=1e5+10;
int fa[MAXN];
int find(int x) {
	if (fa[x]!=x) {
		fa[x]=find(fa[x]);
	}
	return fa[x];
}

//Krusakl
const int MAXM=2e5+10;
struct EDGE {
	int u,v;
	int w;
} edge[MAXM];
bool mycmp(const EDGE &x, const EDGE &y) {
	return x.w<y.w;
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	freopen("00.in", "r", stdin);
	//freopen("09.out", "w", stdout);
	int n,m;
	cin>>n>>m;
	for (int i=0; i<=n; i++) {
		fa[i]=i;
	}
	for (int i=1; i<=m; i++) {
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
	}
	sort(edge+1, edge+m+1, mycmp);
	
	//Kruskal
	int cnt=0;
	int ans=0;
	for (int i=1; i<=m; i++) {
		int x=find(edge[i].u);
		int y=find(edge[i].v);
		if (x==y) {
			continue;
		}
		fa[y]=x;
		cnt++;
		ans+=edge[i].w;
	}
	
	if (cnt<n-1) {
		cout<<"impossible\n";
	} else {
		cout<<ans<<"\n";
	}

	return 0;
}

