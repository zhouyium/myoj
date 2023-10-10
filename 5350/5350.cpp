//http://47.110.135.197/problem.php?id=5350
//5350: Experience

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=2e5+10;
int fa[MAXN];
int sa[MAXN];
int score[MAXN];
int extra[MAXN];
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
	if (sa[x]>sa[y]) {
		swap(x, y);
	}
	fa[x]=y;
	extra[x]=score[y];
	sa[y]+=sa[x];
}

int get(int x) {
	if (x==fa[x]) {
		return score[x];
	} else {
		return score[x]-extra[x]+get(fa[x]);
	}
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
	for (int i=1; i<=m; i++)  {
		string op;
		cin>>op;
		int x,y;
		if (op=="join") {
			cin>>x>>y;
			join(x, y);
		} else if (op=="add") {
			cin>>x>>y;
			x=find(x);
			score[x]+=y;
		} else if (op=="get") {
			cin>>x;
			cout<<get(x)<<"\n";
		}
	}

	return 0;
}

