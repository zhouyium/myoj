//4337: ��3 3 ����3-3��ҽԺ����
//http://47.110.135.197/problem.php?id=4337
//https://www.luogu.com.cn/problem/P1364
//�������� 
#include <bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const LL MO=1e9+7;

const int N=1E6+10;
LL h[N];
LL w[N];//��Ȩ 
LL sz[N];//sz[i]��iΪ����������Ȩ�� 
LL f[N];//f[i]��iΪ������С����� 
/*
ÿ��u�ܴﵽ�ĵ�v
������u��Ϊv��ʱ��v�����������нڵ�ԭ���ľ���Ҫ��u������ֻҪ��
v�ˣ�ÿ�����ľ��붼����1����ô�ܾ���ͼ���sz[v]��
ͬʱ����vΪ����������������нڵ㣬ԭ��ֻҪ��u�����ˣ�����Ҫ��
v��ÿ���ڵ��·�̶�������1����·�̾�������size[1]-size[v]������
size[1]��������Ԥ����������������Ĵ�С����ȥ
size[v]���ǳ���vΪ������������Ľ������
f[v]=f[u]+sz[1]-sz[v]*2
*/
const int M=2*N;
LL e[M],ne[M],idx;
LL ans;//�� 

void init(LL n) {
	idx=0;
	ans=INF;
	for (LL i=0;i<=n;i++) {
		h[i]=-1;
		w[i]=sz[i]=0;
		f[i]=0;
	}
}

void add(LL a,LL b) {
	//a->b
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}

//u:��ǰ�ڵ�
//fath:���׽ڵ�
//deep:��ǰ��� 
void dfs(LL u,LL fath,LL deep) {
	sz[u]=w[u];//�Լ��ĵ�Ȩ
	for (LL i=h[u];i!=-1;i=ne[i]) {
		LL v=e[i];
		if (v==fath) {
			continue;
		}
		dfs(v,u,deep+1);
		sz[u]+=sz[v];//���µ�Ȩ 
	}
	//����f[1]
	f[1] +=w[u]*deep;
}

void dp(LL u,LL fath) {
	for (LL i=h[u];i!=-1;i=ne[i]) {
		LL v=e[i];
		if (v==fath) {
			continue;
		}
		f[v]=f[u]+sz[1]-sz[v]*2;
		dp(v,u);
	}
	ans=min(ans,f[u]);//���´� 
}

void solve() {
	LL n;
	cin>>n;
	init(n);
	for (LL i=1;i<=n;i++) {
		LL u,v;
		cin>>w[i];//��ȡ��Ȩ 
		cin>>u>>v;
		if (u) {
			//u Ϊ������
			add(i,u);
			add(u,i);
		}
		if (v) {
			//v Ϊ������
			add(i,v);
			add(v,i);
		}
	}
	
	dfs(1,0,0);
	dp(1,0);
	
	cout<<ans<<"\n";
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	LL T=1;
	//cin>>T;
	for (LL i=1; i<=T; i++) {
		//cout<<i<<"\n";
		solve();
	}

	return 0;
}
