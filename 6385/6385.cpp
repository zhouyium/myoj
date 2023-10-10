//https://www.luogu.com.cn/problem/P5318
//P5318 【深基18.例3】查找文献

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1E6+10;

LL n,m;
vector<vector<LL>> adj;
vector<bool> vis_dfs;
vector<bool> vis_bfs;
vector<LL> dis;

void bfs(LL st) {
	vis_bfs.resize(n+1, false);
	vis_bfs[st]=true;
	
	queue<LL> que;
	que.push(st);
	
	while (que.size()) {
		LL u=que.front();
		que.pop();
		
		cout<<u<<" ";
		
		for (const auto &v : adj[u]) {
			if (vis_bfs[v]==false) {
				vis_bfs[v]=true;
				que.push(v);
			}
		}
	}
	cout<<"\n";
}

void dfs(LL u) {
	if (vis_dfs[u]) {
		return;
	}
	vis_dfs[u]=true;
	cout<<u<<" ";
	
	for (const auto &v:adj[u]) {
		dfs(v);
	}
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("07.in", "r", stdin);
	//freopen("07.out", "w", stdout);
	cin>>n>>m;
	adj.resize(n+1);
	for (LL i=1; i<=m; i++) {
		LL u,v;
		cin>>u>>v;
		adj[u].push_back(v); //u->v
	}
	
	//排序
	for (LL i=1; i<=n; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	
	//DFS
	vis_dfs.resize(n+1, false);
	dfs(1);
	cout<<"\n";
	
	//BFS
	bfs(1);

	return 0;
}


