//http://47.110.135.197/problem.php?id=5348
//5348: Disjoint Sets Union

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=1e5+10;
int fa[MAXN];
int sa[MAXN];

int n;
void init() {
	for (int i=0; i<=n; i++) {
		fa[i]=i;
		sa[i]=1;
	}
}

int find(int x) {
	if (fa[x]!=x) {
		fa[x]=find(fa[x]);
	}
	return fa[x];
}

void join(int x, int y) {
	int px=find(x);
	int py=find(y);
	if (px!=py) {
		fa[px]=py;
		sa[py]+=px;
	}
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("9.in", "r", stdin);
	//freopen("9.out", "w", stdout);
	int m;
	cin>>n>>m;
	init();
	for (int i=1; i<=m; i++) {
		string op;
		int x,y;
		cin>>op>>x>>y;
		if (op=="union") {
			join(x, y);
		} else if (op=="get") {
			int px=find(x);
			int py=find(y);
			if (px==py) {
				cout<<"YES\n";
			} else {
				cout<<"NO\n";
			}
		}
	}

	return 0;
}

