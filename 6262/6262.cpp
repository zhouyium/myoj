//6262: p节点
//http://47.110.135.197/problem.php?id=6262
 
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1E3+10;
LL edge[MAXN][MAXN];
LL cnt[MAXN];

int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	LL T;
	cin>>T;
	while (T--) {
		LL n;
		cin>>n;
		
		fill(cnt, cnt+MAXN-2, 0);
		fill(edge[0], edge[0]+(MAXN-1)*(MAXN-1), 0);
		
		for (LL i=1; i<n; i++) {
			LL u,v;
			cin>>u>>v;
			cnt[u]++;
			cnt[v]++;
			edge[u][v]=1;
			edge[v][u]=1;
		}
		
		//统计
		LL ans=0;
		for (LL i=1; i<=n; i++) {
			LL maxx=0;
			for (LL j=1; j<=n; j++) {
				if (edge[i][j] && i!=j) {
					maxx=max(maxx, cnt[j]);
				}
			}
			ans+=(cnt[i]>maxx);
		}
		cout<<ans<<"\n";
	}

	return 0;
}

