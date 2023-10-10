#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const LL INF=0x3f3f3f3f3f3f3f3f;
const int N=2e2+10;
LL g[N][N];
LL dis[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	LL n,x,y;
	cin>>n>>x>>y;
	//≥ı ºªØ 
	for (LL i=1; i<=n; i++) {
		for (LL j=1; j<=n; j++) {
			if (i==j) {
				g[i][j]=0;
			} else {
				g[i][j]=INF;
			}
		}
	}
	for (LL i=1; i<=n; i++) {
		cin>>dis[i];
		dis[i]=-dis[i];
	}
	for (LL i=1; i<n; i++) {
		LL u,v;
		cin>>u>>v;
		g[u][v]=dis[u];
	}
	//floyd
	for (LL k=1; k<=n; k++) {
		for (LL i=1; i<=n; i++) {
			for (LL j=1; j<=n; j++) {
				g[i][j]=min(g[i][j], g[i][k]+g[k][j]);
			}
		}
	}
	
	if (g[x][y]>=INF)  {
		cout<<"-1\n";
	} else {
		cout<<-(g[x][y]+dis[y])<<"\n";
	}

	return 0;
}
