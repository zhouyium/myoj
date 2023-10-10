//6259: 水图
//http://47.110.135.197/problem.php?id=6259

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=5E4+10;

struct NODE {
    LL v,w;
};
vector<NODE> adj[MAXN];
bool vis[MAXN];
LL n;
LL ans;

//now表示当前的节点
//dis表示距离
void dfs(LL now, LL dis) {
    vis[now]=1;
    if (adj[now].size()==1 && vis[adj[now][0].v]) {
        //都访问过
        ans=max(ans, dis);
        return;
    }

    for (LL i=0; i<adj[now].size(); i++) {
        if (false==vis[adj[now][i].v]) {
            dfs(adj[now][i].v, dis+adj[now][i].w);
        }
    }
}

int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	LL x;
	cin>>n>>x;

    LL sum=0;
	for (LL i=1; i<n; i++) {
		LL u,v,w;
		cin>>u>>v>>w;
        adj[u].push_back({v,w});
		adj[v].push_back({u,w});
        sum+=w;
	}

    dfs(x, 0);
    cout<<sum*2-ans<<"\n";

	return 0;
}

