#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1E5+10;

struct NODE {
	LL v,w;
}; 
vector<NODE> adj[MAXN];
LL deg_in[MAXN];
LL deg_out[MAXN];

int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	LL n,m;
	cin>>n>>m;
	for (LL i=1; i<=m; i++) {
		LL u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({v, w});
		deg_out[u]++;
		deg_in[v]++;
	}
	
	LL q;
	cin>>q;
	for (LL i=1; i<=q; i++) {
		LL x;
		cin>>x;
		cout<<x<<" "<<deg_out[x]<<" "<<deg_in[x]<<"\n";
	}

	return 0;
}

