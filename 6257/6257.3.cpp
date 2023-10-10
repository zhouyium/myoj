//http://47.110.135.197/problem.php?id=6256
//6256: 图的基础使用 1：查询是否存在某条边
//使用邻接表 
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1E3+10;
vector<LL> adj[MAXN];

bool find_edge(LL u, LL v) {
	for (LL i=0; i<adj[u].size(); i++) {
		if (adj[u][i]==v) {
			return true;
		}
	}
	return false;
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	LL n,m;
	cin>>n>>m;
	for (LL i=1; i<=m; i++) {
		LL u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		//adj[v].push_back(u);
	}
	LL q;
	cin>>q;
	for (LL i=1; i<=q; i++) {
		LL u,v;
		cin>>u>>v;
		if (find_edge(u, v)) {
			cout<<"Yes\n";
		} else {
			cout<<"No\n";
		}
	}

	return 0;
}

