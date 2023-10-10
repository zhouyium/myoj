//http://47.110.135.197/problem.php?id=5715
//http://acm.hdu.edu.cn/showproblem.php?pid=1233
//5715: ³©Í¨¹¤³Ì II 

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//DSU
const int MAXN=1e2+10;
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
const int MAXM=5e4+10;
struct EDGE {
	int x,y,w;
} edge[MAXM];
bool mycmp(const EDGE &a, const EDGE &b) {
	return a.w<b.w;
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int n;
	while (cin>>n && n!=0) {
		init(n);
		int m=n*(n-1)/2;
		for (int i=1; i<=m; i++) {
			cin>>edge[i].x>>edge[i].y>>edge[i].w;
		}
		sort(edge+1, edge+m+1, mycmp);
		
		//MST
		int ans=0;
		for (int i=1; i<=m; i++) {
			int a=find(edge[i].x);
			int b=find(edge[i].y);
			if (a==b) {
				continue;
			}
			
			fa[b]=a;
			ans+=edge[i].w;
		}
		
		cout<<ans<<"\n";
	}

	return 0;
}

