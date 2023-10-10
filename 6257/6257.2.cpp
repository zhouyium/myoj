//6256: 图的基础使用 1
//http://47.110.135.197/problem.php?id=6256
//使用邻接矩阵 
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1E3+10;
LL a[MAXN][MAXN];
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
		a[u][v]=1;
	}
	LL q;
	cin>>q;
	for (LL i=1; i<=q; i++) {
		LL u,v;
		cin>>u>>v;
		if (a[u][v]==1) {
			cout<<"Yes\n";
		} else {
			cout<<"No\n";
		}
	}
	return 0;
}

