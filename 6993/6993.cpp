#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=1e4+10;
const int M=1e5+10;
LL h[N];//��ͼ
LL hn[N];//��ͼ 
LL e[M], ne[M], idx;
LL dfn[N], low[N], ts;
LL stk[N], top;
bool instk[N];
LL scc_cnt;
LL scc[N];
LL sz[N];
LL din[N];//��� 
LL dout[N];//����

LL init(LL n) {
	idx=ts=top=scc_cnt=0;
	for (LL i=0; i<=n; i++) {
		h[i]=hn[i]=-1;
		dfn[i]=instk[i]=sz[i]=din[i]=dout[i]=0;
	}
}

//�������� 
void add(LL a,LL b,LL h[]) {
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}

void tarjan(LL u) {
	dfn[u]=low[u]=++ts;
	stk[++top]=u;
	instk[u]=true;
	
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
			instk[v]=false;
			scc[v]=scc_cnt;
			sz[scc_cnt]++;
		} while(u!=v);
	}
}

void solve() {
	LL n,m;
	cin>>n>>m;
	init(n);
	for (LL i=1; i<=m; i++) {
		LL a,b;
		cin>>a>>b;
		add(a,b,h);
	}
	
	//SCC
	for (LL i=1; i<=n; i++) {
		if (0==dfn[i]) {
			tarjan(i);
		}
	}
	
	//����
	for (LL u=1; u<=n; u++) {
		//����u�����г���
		for (LL i=h[u]; i!=-1; i=ne[i]) {
			LL v=e[i];//u->v
			LL su=scc[u];//u����Ϊsu 
			LL sv=scc[v];//v����Ϊsv 
			if (su!=sv) {
				//������ͼ
				//su->sv
				add(su,sv,hn); 
				din[sv]++;
				dout[su]++;
			}
		}
	}
	
	//���ѵ㣺����ͼ���Ҵ� 
	LL ans=0;
	LL cnt=0;//ͳ�Ƴ���Ϊ0�ĵ�����
	//������ͼ���е㣬����ͼ��ĳ���
	//��ͼֻ��scc_cnt���� 
	for (LL i=1; i<=scc_cnt; i++) {
		if (dout[i]==0) {
			cnt++;
			ans+=sz[i];
		}
		if (cnt>1) {
			cout<<"0\n";
			return;
		}
	}
	cout<<ans<<"\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);

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

