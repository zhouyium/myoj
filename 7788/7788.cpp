#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=1e4+10;
const int M=2e5+10;
//ע�����Ҫ����ͼ����Ҫ��ԭͼ��2������ 
LL h[N], hn[N];
LL e[M], ne[M], idx;
LL dfn[N], low[N], ts;
LL stk[N], top;
bool instk[N];
LL scc_cnt;
LL scc[N];
LL a[N];//��Ȩ 
LL sum[N];//�������еĵ�Ȩ 

LL f[N];//f[i]��ʾ���Ϊi�ĳ������Ȩֵ�� 

void init(LL n) {
	idx=ts=top=scc_cnt=0;
	for (LL i=0; i<=n; i++) {
		h[i]=hn[i]=-1;
		dfn[i]=instk[i]=0;
		sum[i]=0; 
		f[i]=0; 
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
		} else if (instk[v]) {
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
			//����һ����Ȩ 
			sum[scc_cnt]+=a[v];
		}while(u!=v);
	}
}

void solve() {
	LL n,m;
	cin>>n>>m;
	init(n);
	for (LL i=1; i<=n; i++) {
		cin>>a[i];
	}
	for (LL i=1; i<=m; i++) {
		LL a,b;
		cin>>a>>b;
		add(a,b,h);
	}
	
	//scc
	for (LL i=1; i<=n; i++) {
		if (0==dfn[i]) {
			tarjan(i);
		}
	}
	
	//���㽨ͼ
	for (LL u=1; u<=n; u++) {
		for (LL i=h[u]; i!=-1; i=ne[i]) {
			LL v=e[i];
			LL su=scc[u];
			LL sv=scc[v];
			if (su!=sv) {
				add(su,sv,hn);
				//din[sv]++;
				//dout[su]++; 
			}
		}
	}
	
	//���ѵĵط�����ͼ���Ҵ� 
	//ע����ͼ�� hn 
	//��һ������
	for (LL u=1; u<=scc_cnt; u++) {
		LL maxx=0;//��ʾ��u�����ĳ���������Ȩ 
		for (LL i=hn[u]; i!=-1; i=ne[i]) {
			LL v=e[i];
			maxx=max(maxx,f[v]);
		}
		f[u]=sum[u]+maxx;
	}
	
	//�Ҵ� 
	LL res=0;
	for (LL i=1; i<=scc_cnt; i++) {
		res=max(res,f[i]);
	}
	cout<<res<<"\n";
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

