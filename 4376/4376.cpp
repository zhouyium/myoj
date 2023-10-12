#include <bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL, LL>;

const LL INF=0x3f3f3f3f3f3f3f3f;

const int N=5e5+10;
vector<PLL> adj[N];
LL dis[N];
bool vis[N];//表示顶点 i 是否在队列 
LL n;

void spfa(LL st) {
	//初始化
	for (LL i=0; i<=n; i++) {
		dis[i]=INF;
		vis[i]=0;
	}
	
	//处理起点 
	dis[st]=0;
	vis[st]=1; 

	//定义队列
	queue<LL> que;
	que.push(st);
	
	while (que.size()) {
		LL u=que.front();que.pop();
		vis[u]=0;
		
		//遍历u的所有出边
		for (const auto &node : adj[u]) {
			LL v=node.first;
			LL w=node.second;
			
			//能不能松弛
			if (dis[v]>dis[u]+w) {
				dis[v]=dis[u]+w;
				
				//判断v是否在队列
				if (vis[v]==false) {
					vis[v]=1;
					que.push(v);
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	LL m,st;
	cin>>n>>m>>st;
	for (LL i=1; i<=m; i++) {
		LL a,b,c;
		cin>>a>>b>>c;
		adj[a].push_back({b,c});
		//adj[b].push_back({a,c});
	}
	
	spfa(st);
	
	for (LL i=1; i<=n; i++) {
		cout<<dis[i]<<" ";
	}
	cout<<"\n";
	//cout<<dis[n]<<"\n";
}
