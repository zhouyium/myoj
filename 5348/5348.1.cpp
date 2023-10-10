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
	if (fa[x]==x) {
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
	if (sa[x]<sa[y]) {
		swap(x, y);
	}
	fa[y]=x;
	sa[x]+=sa[y];
}

int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	freopen("10.in", "r", stdin);
	//freopen("1.out", "w", stdout);
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
			x=find(x);
			y=find(y);
			if (x==y) {
				cout<<"YES\n";
			} else {
				cout<<"NO\n";
			}
		}
	}

	return 0;
}

