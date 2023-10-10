#include <bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const LL MO=1e5+3;

const int N=1E6+10;
LL h[N], vis[N], dis[N], cnt[N];
const int M=2e6+10;
LL e[M],ne[M],w[M],idx;

void add(LL a,LL b,LL c) {
	e[idx]=b;
	w[idx]=c;
	ne[idx]=h[a];
	h[a]=idx++;
}

void dij(LL st) {
	memset(dis, 0x3f, sizeof dis);
	memset(vis, false, sizeof vis);
	memset(cnt, 0, sizeof cnt);
	
	dis[st]=0;
	cnt[st]=1;
	priority_queue<PLL, vector<PLL>, greater<PLL>> que;
	que.push({0,st});
	
	while (que.size()) {
		auto node=que.top();
		que.pop();
		
		LL u=node.second;
		if (vis[u]) {
			continue;
		}
		vis[u]=true;
		
		for (LL i=h[u]; i!=-1; i=ne[i]) {
			LL v=e[i];
			if (dis[v]>dis[u]+w[i]) {
				//¸ü½ü 
				dis[v]=dis[u]+w[i];
				cnt[v]=cnt[u];
				que.push({dis[v],v});
			} else if (dis[v]==dis[u]+w[i]){
				cnt[v]=(cnt[v]+cnt[u]);
			}
		}
	}
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	
	memset(h, -1, sizeof h);
	
	LL n,m;
	cin>>n>>m;
	for (LL i=1; i<=m; i++) {
		LL a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
	}
	
	dij(1);
	if (dis[n]==INF) {
		cout<<"No answer\n";
	} else {
		cout<<dis[n]<<" "<<cnt[n]<<"\n";
	}

	return 0;
}

