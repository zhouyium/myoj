//6630: 加边的无向图
//http://47.110.135.197/problem.php?id=6630
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1E6+10;
LL fa[N];

void init(LL n) {
	for (LL i=0; i<=n; i++) {
		fa[i]=i;
	}
}
LL find(LL x) {
	if (fa[x]!=x) {
		fa[x]=find(fa[x]);
	}
	return fa[x];
}
bool join(LL x, LL y) {
	x=find(x);
	y=find(y);
	if (x==y) {
		return false;
	}
	fa[y]=x;
	return true;
}
int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);
	LL n,m;
	cin>>n>>m;
	
	LL ans=n;
	init(n);
	for (LL i=1; i<=m; i++) {
		LL u,v;
		cin>>u>>v;
		if (true==join(u,v)) {
			ans--;
		}
	}
	cout<<ans-1<<"\n";

	return 0;
}

