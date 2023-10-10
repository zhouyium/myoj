//http://47.110.135.197/problem.php?id=4335
//找树根和孩子
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1E3+10;
vector<LL> e[MAXN];
vector<LL> nodes, indeg(MAXN);

int main() {
#if 0
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
		e[u].push_back(v);
		indeg[v]++;
		nodes.emplace_back(u);
		nodes.emplace_back(v);
	}

	//入度为0就是跟节点
	LL root=-1, maxx=-1, max_node;
	for (const auto& node : nodes) {
		if (indeg[node]==0) {
			root=node;
		}
		LL child_size=e[node].size();
		if (child_size>maxx) {
			max_node = node;
			maxx = child_size;
		}
	}

	//输出
	sort(e[max_node].begin(), e[max_node].end());
	cout<<root<<"\n"<<max_node<<"\n";
	for (const auto &node:e[max_node]) {
		cout<<node<<" ";
	}
	cout<<"\n";

	return 0;
}

