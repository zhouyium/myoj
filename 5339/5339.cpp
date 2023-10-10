//http://47.110.135.197/problem.php?id=5339
//5339: 【模板】并查集
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e4+10;
int parent[MAXN];//父亲

int n;
void init() {
	for (int i=1; i<=n; i++) {
		parent[i]=i;
	}
} 
int find(int x) {
	if (parent[x]!=x) {
		parent[x]=find(parent[x]);
	}
	return parent[x];
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int m;
	scanf("%d%d", &n, &m);
	init();
	for (int i=1; i<=m; i++) {
		int x,y,z;
		scanf("%d%d%d", &z, &x, &y);
		if (1==z) {
			parent[find(x)]=find(y);
		} else if (2==z) {
			if (find(x)==find(y)) {
				printf("Y\n");
			} else {
				printf("N\n");
			}
		}
	}

	return 0;
}


