//http://47.110.135.197/problem.php?id=5716
//http://acm.hdu.edu.cn/showproblem.php?pid=1863

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//DSU
const int MAXN=1e5+10;
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
struct EDGE {
	int x,y,w;
} edge[MAXN];
bool mycmp(const EDGE &a, const EDGE &b) {
	return a.w<b.w;
}

const int INF=1e9+10;

int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int n;//µÀÂ·
	int m;//´å×¯ 
	while (cin>>n>>m && n!=0) {
		init(m);
		
		for (int i=1; i<=n; i++) {
			cin>>edge[i].x>>edge[i].y>>edge[i].w;
		}
		sort(edge+1, edge+n+1, mycmp);
		
		int ans=0;
		int cnt=0;
		for (int i=1; i<=n; i++) {
			int x=find(edge[i].x);
			int y=find(edge[i].y);
			if (x==y) {
				continue;
			}
			
			cnt++;
			fa[y]=x;
			ans=ans+edge[i].w;
		}
		
		if (cnt<m-1) {
			cout<<"?\n";
		} else {
			cout<<ans<<"\n";
		}
	}

	return 0;
}

