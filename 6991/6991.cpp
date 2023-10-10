#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=1e5+10;
LL h[N];
LL dis[N];
LL cnt[N];
bool vis[N];
LL n;

const int M=3e5+10;
LL e[M], w[M], ne[M], idx;

void add(LL a,LL b,LL c) {
	e[idx] = b;
	w[idx] = c;
	ne[idx]= h[a];
	h[a]   = idx++;
}

//vis[i] 表示顶点i是否在队列 
bool spfa(LL st) {
	memset(dis, -0x3f, sizeof dis);
	
	//起点
	dis[st] = 0;
	vis[st] = 1;//已经放入队列
	
	queue<LL> que;
	que.push(st);
	
	while (que.size()) {
		LL u=que.front();
		que.pop();
		
		vis[u] = 0;//顶点u不在队列
		
		//遍历所有出边
		for (LL i=h[u]; i!=-1; i=ne[i]) {
			LL v=e[i];
			if (dis[v]<dis[u]+w[i]) {
				dis[v]=dis[u]+w[i];
				cnt[v]=cnt[u]+1;
				if (cnt[v]>=n+1) {
					return true;
				}
				
				if (vis[v]==false) {
					que.push(v);
					vis[v]=1;
				}
			}
		}
	}
	return false;
}

void solve() {
	memset(h, -1, sizeof h);
	LL m;
	cin>>n>>m;
	for (LL i=1; i<=m; i++) {
		LL x,a,b;
		cin>>x>>a>>b;
		if (x==1) {
			//a=b -> a=b+0, b=a+0
			//a=b+0
			add(b,a,0);
			//adj[b].push_back({a,0});//b->a 0
			//b=a+0  a->b 0
			add(a,b,0);
			//adj[a].push_back({b,0});
		} else if (x==2) {
			//a<b -> a+k=b,(k>=1) -> a+1=b -> a->b 1
			add(a,b,1);
			//adj[a].push_back({b,1});
		} else if (x==3) {
			//a>=b -> a=b+k,(k>=0) -> a=b+0 -> b->a 0
			add(b,a,0);
			//adj[b].push_back({a,0});
		} else if (x==4) {
			//a>b -> a=b+k,(k>=1) -> a=b+1 -> b->a 1
			add(b,a,1);
			//adj[b].push_back({a,1});
		} else if (x==5) {
			//a<=b -> a+k=b,(k>=0) -> a+0=b -> a->b 0
			add(a,b,0);
			//adj[a].push_back({b,0});
		}
	}
	//要求每个小朋友都要分到糖果。 -> a[i]>=1 -> a[i]=1
	//加入一个超级源点 0 -> a[0]+1=a[i] -> a[0]->a[i] 1
	for (LL i=1; i<=n; i++) {
		add(0,i,1);
		//adj[0].push_back({i,1});
	}
	
	if (spfa(0)) {
		//有环
		cout<<"-1\n";
		return; 
	}
	LL res=0;
	for (LL i=1; i<=n; i++)  {
		res+=dis[i];
	}
	cout<<res<<"\n";
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

