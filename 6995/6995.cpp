#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=1e5+10;
const int M=4*N;
LL h[N], hn[N];
LL e[M], ne[M], idx;
LL dfn[N], low[N], ts;
LL stk[N], top;
bool instk[N];
LL scc_cnt;
LL scc[N];
LL sz[N];
LL din[N], dout[N];

void init(LL n) {
	idx=ts=top=scc_cnt=0;
	for (LL i=0; i<=n; i++) {
		h[i]=hn[i]=-1;
		dfn[i]=instk[i]=sz[i]=din[i]=dout[i]=0;
	}
}

void add(LL a,LL b,LL h[]) {
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}

void tarjan(LL u) {
	dfn[u]=low[u]=++ts;
	stk[++top]=u;
	instk[u]=1;
	
	for (LL i=h[u]; i!=-1; i=ne[i]) {
		LL v=e[i];
		if (0==dfn[v]) {
			tarjan(v);
			low[u]=min(low[u],low[v]);
		} else if (true==instk[v]) {
			low[u]=min(low[u],dfn[v]);
		}
	}
	
	if (dfn[u]==low[u]) {
		scc_cnt++;
		LL v;
		do {
			v=stk[top--];
			instk[v]=0;
			scc[v]=scc_cnt;
			sz[scc_cnt]++;
		}while(u!=v);
	}
}

void solve() {
	LL n;
	cin>>n;
	init(n);
	for (LL i=1; i<=n; i++) {
		LL x;
		while (cin>>x) {
			if (x==0) {
				break;
			}
			//i->x
			add(i,x,h);
		}
	}
	
	//SCC
	for (LL i=1; i<=n; i++) {
		if (0==dfn[i]) {
			tarjan(i);
		}
	}
	
	//缩点建图
	for (LL u=1; u<=n; u++) {
		for (LL i=h[u]; i!=-1; i=ne[i]) {
			LL v=e[i];//u->v;
			LL su=scc[u];
			LL sv=scc[v];//su->sv
			if (su!=sv) {
				add(su,sv,hn);
				din[sv]++;
				dout[su]++;
			}
		}
	}
	
	//在新图上找答案
	LL in=0, out=0;
	for (LL i=1; i<=scc_cnt; i++) {
		if (din[i]==0) {
			in++;
		}
		if (dout[i]==0) {
			out++;
		}
	}
	
	cout<<in<<"\n";
	if (1==scc_cnt) {
		cout<<"0\n";
	} else {
		//在一个有向图中，加至少几条边，使得图变成一个SCC 
		cout<<max(in,out)<<"\n";
	}
}

int main() {
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie (0);

	//freopen("marathon.in", "r", stdin);
	//freopen("marathon.out", "w", stdout);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

