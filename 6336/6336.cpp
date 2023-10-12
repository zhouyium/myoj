#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
//long long 8B 
const LL INF=0x7FFFFFFF;
const double EPS=1e-10;

const int N=1e6+10;
LL h[N];
LL dis[N];
bool vis[N]; 
LL n;

const int M=2e6+10;
LL e[M];//e[i]表示到哪个顶点
LL w[M];//对应的权
LL ne[M];//下一条边
LL idx;

void add(LL a,LL b,LL c) {
	//a->b c
	e[idx] = b;
	w[idx] = c;
	ne[idx]= h[a];//头插法 
	h[a]   = idx++;
}

void dij(LL st) {
	for (LL i=1; i<=n; i++) {
		dis[i] = INF;
		vis[i] = false;
	}
	
	dis[st] = 0;
	
	priority_queue<PLL, vector<PLL>, greater<PLL>> que;
	que.push({dis[st], st});
	
	while (que.size()) {
		auto t = que.top();
		que.pop();
		
		LL u = t.second;
		if (vis[u]) {
			continue;
		}
		vis[u] = true;
		
		for (LL i=h[u]; i!=-1; i=ne[i]) {
			LL v = e[i];
			if (dis[v] > dis[u] + w[i]) {
				dis[v] = dis[u] + w[i];
				if (vis[v] == false) {
					que.push({dis[v], v});
				}
			}
		}
	}
}

void solve() {
	memset(h, -1, sizeof h);
	LL m,st;
	cin>>n>>m>>st;
	for (LL i=1; i<=m; i++) {
		LL x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
		//adj[x].push_back({y,z});
	}
	
	dij(st);
	
	for (LL i=1; i<=n; i++) {
		cout<<dis[i]<<" ";
	}
	cout<<"\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

