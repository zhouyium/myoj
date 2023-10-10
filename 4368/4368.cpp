//http://47.110.135.197/problem.php?id=4368
//最小花费
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
using PDL=pair<double, LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-7;

const int N=2e3+10;
vector<PDL> adj[N];
double dis[N];
bool vis[N];

void spfa(LL st) {
	dis[st] = 1;
	vis[st] = true;
	
	queue<LL> que;
	que.push(st);
	
	while (que.size()) {
		LL u=que.front();
		que.pop();
		
		vis[u] = false;
		
		for (const auto &t : adj[u]) {
			LL v = t.second;
			double w = t.first;
			if (dis[v]<dis[u]*w) {
				dis[v] = dis[u]*w;
				if (vis[v]==false) {
					que.push(v);					
					vis[v] = true;
				}
			}
		}
	}
}

void dij(LL st) {
	dis[st]=1;
	
	priority_queue<PDL, vector<PDL>, less<PDL>> que;
	que.push({0, st});
	
	while (que.size()) {
		auto node = que.top();
		que.pop();
		
		LL u = node.second;
		if (vis[u]) {
			continue;
		}
		vis[u] = true;
		
		for (const auto &t : adj[u]) {
			LL v = t.second;
			double w = t.first;
			if (dis[v]<dis[u]*w) {
				dis[v] = dis[u]*w;
				que.push({dis[v], v});
			}
		}
	}
}

void solve() {
	LL n,m;
	cin>>n>>m;
	for (LL i=1; i<=m; i++) {
		LL a,b,c;
		cin>>a>>b>>c;
		double z=(100.0-c)/100;
		adj[a].push_back({z,b});
		adj[b].push_back({z,a});
	}
	LL st,ed;
	cin>>st>>ed;
	
	spfa(st);
	
	cout<<fixed<<setprecision(8)<<100.0/dis[ed]<<"\n";
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

