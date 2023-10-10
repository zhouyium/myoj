#include <bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const LL MO=1e9+7;

const int N=1E6+10;
LL deep[N];
vector<LL> adj[N];
LL maxx;

void dfs(LL u,LL fath) {
	deep[u]=deep[fath]+1;
	maxx=max(maxx, deep[u]);
	for (const auto &v:adj[u]) {
		if (v!=fath) {
			dfs(v,u);
		}
	}
}
 
void solve() {
	LL n;
	cin>>n;
	for (LL i=1;i<=n;i++) {
		LL x,y;
		cin>>x>>y;
		if (x==0&&y==0) {
			continue;
		}
		adj[i].push_back(x);
		adj[i].push_back(y);
	}
	
	dfs(1,0);
	cout<<maxx<<"\n";
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	LL T=1;
	//cin>>T;
	for (LL i=1; i<=T; i++) {
		//cout<<i<<"\n";
		solve();
	}

	return 0;
}
