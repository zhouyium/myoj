//6256: 图的基础使用 1
//http://47.110.135.197/problem.php?id=6256
//直接存边
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1E3+10;
struct EDGE {
	LL u,v;
};
vector<EDGE> e;
LL n,m;
bool find_edge(LL u, LL v) {
	for (LL i=0; i<e.size(); i++) {
		if (e[i].u==u && e[i].v==v) {
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
	
	cin>>n>>m;
	for (LL i=1; i<=m; i++) {
		LL u,v;
		cin>>u>>v;
		e.push_back({u,v});
		e.push_back({v,u});
	}
	LL q;
	cin>>q;
	for (LL i=1; i<=q; i++) {
		LL u,v;
		cin>>u>>v;
		if (find_edge(u,v)) {
			cout<<"Yes\n";
		} else {
			cout<<"No\n";
		}
	}
	return 0;
}

