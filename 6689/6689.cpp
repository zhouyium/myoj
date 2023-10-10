//6689: 有多少个答案是错误的
//http://47.110.135.197/problem.php?id=6689
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2E5+10;
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
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	LL n,m;
	while (cin>>n>>m) {
		//初始化并查集 
		for (LL i=0; i<=n; i++) {
			fa[i]=i;
			w[i]=0;
		}
		
		LL ans=0;
		for (LL i=1; i<=m; i++) {
			LL a,b,c;
			cin>>a>>b>>c;
			a--;
			
			LL pa=find(a);
			LL pb=find(b);
			if (pa==pb) {
				if (w[a]-w[b]!=c) {
					ans++;
				}
			} else {
				fa[pa] = pb;
				w[pa] = c-w[a]+w[b];
			}
		}
		cout<<ans<<"\n";		
	}
	

	return 0;
}

