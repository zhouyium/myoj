//http://47.110.135.197/problem.php?id=5733
//https://www.luogu.com.cn/problem/P3366
//5733: 【模板】最小生成树

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//DSU
const int MAXN=5e3+10;
int fa[MAXN];
int sa[MAXN];
void init(int n) {
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

//MST
const int MAXM=2e5+10;
struct EDGE {
	int x, y, w;
} edge[MAXM];
bool mycmp(const EDGE &a, const EDGE &b) {
	return a.w<b.w;
}

int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int n,m;
	cin>>n>>m;
	init(n);
	for (int i=1; i<=m; i++) {
		cin>>edge[i].x>>edge[i].y>>edge[i].w;
	}
	sort(edge+1, edge+m+1, mycmp);
	
	//MST
	int ans=0;
	int sum=0;
	for (int i=1; i<=m; i++) {
		int x=find(edge[i].x);
		int y=find(edge[i].y);
		if (x==y) {
			continue;
		}
		
		sum++;
		fa[y]=x;
		ans+=edge[i].w;
	}

	if (sum<n-1) {
		cout<<"orz\n";
	} else {
		cout<<ans<<"\n";
	}
	
	return 0;
}

