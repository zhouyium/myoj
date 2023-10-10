#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=3e5+10;
int fa[MAXN];
int sa[MAXN];
int mina[MAXN];
int maxa[MAXN];
int n;
void init() {
	for (int i=0; i<=n; i++) {
		fa[i]=i;
		sa[i]=1;
		mina[i]=i;
		maxa[i]=i;
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
	mina[y]=min(mina[y], mina[x]);
	maxa[y]=max(maxa[y], maxa[x]);
}
int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int m;
	cin>>n>>m;
	init();
	for (int i=1; i<=m; i++) {
		string op;
		cin>>op;
		int x,y;
		if (op=="union") {
			cin>>x>>y;
			join(x,y);
		} else if (op=="get") {
			cin>>x;
			x=find(x);
			cout<<mina[x]<<" "<<maxa[x]<<" "<<sa[x]<<"\n";
		}
	}

	return 0;
}

