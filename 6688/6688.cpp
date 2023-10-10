//6688: 分数调查
//http://47.110.135.197/problem.php?id=6688
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1E5+10;
LL fa[N];//父亲 
LL w[N];//权

LL find(LL x) {
	if (fa[x]!=x) {
		LL t=fa[x];
		fa[x]=find(fa[x]);
		w[x] += w[t];
	}
	return fa[x];
}
 
int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	LL n,m,q;
	cin>>n>>m>>q;
	//初始化并查集 
	for (LL i=1; i<=n; i++) {
		fa[i]=i;
		w[i]=0;
	}
	for (LL i=1; i<=m; i++) {
		LL x,y,s;
		cin>>x>>y>>s;
		
		//
		LL px=find(x);
		LL py=find(y);
		if (px!=py) {
			//不是同一个父亲
			fa[px] = py;
			w[px] = s-w[x]+w[y];
		}
	}
	
	for (LL i=1; i<=q; i++) {
		LL x,y;
		cin>>x>>y;
		if (find(x)!=find(y)) {
			//不是同一个父亲
			cout<<"-1\n"; 
		} else {
			cout<<w[x]-w[y]<<"\n";
		}
	}

	return 0;
}

