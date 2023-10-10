//http://47.110.135.197/problem.php?id=5638
//5638: 连通块中点的数量

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
	if (x==fa[x]) {
		return x;
	}
	return find(fa[x]);
}
void join(int x, int y) {
	x=find(x);
	y=find(y);
	if (x==y) {
		return;
	}
	if (sa[x]>sa[y]) {
		swap(x, y);
	}
	fa[x]=y;
	sa[y]+=sa[x];
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
		cin>>op;
		if (op=="C") {
			cin>>x>>y;
			join(x, y);
		} else if (op=="Q1") {
			cin>>x>>y;
			x=find(x);
			y=find(y);
			if (x==y) {
				cout<<"Yes\n";
			} else {
				cout<<"No\n";
			}
		} else if (op=="Q2") {
			cin>>x;
			x=find(x);
			cout<<sa[x]<<"\n";
		}
	}

	return 0;
}

