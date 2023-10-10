//4337: §3 3 【例3-3】医院设置
//http://47.110.135.197/problem.php?id=4337
//https://www.luogu.com.cn/problem/P1364
//树的重心 
#include <bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const LL MO=1e9+7;

const int N=1E6+10;
LL h[N];
LL w[N];//点权 
LL sz[N];//sz[i]以i为跟的子树点权和 
LL f[N];//f[i]以i为跟的最小距离和 
/*
每个u能达到的点v
当根从u变为v的时候，v的子树的所有节点原本的距离要到u，现在只要到
v了，每个结点的距离都减少1，那么总距离就减少sz[v]，
同时，以v为根的子树以外的所有节点，原本只要到u就行了，现在要到
v，每个节点的路程都增加了1，总路程就增加了size[1]-size[v]，其中
size[1]就是我们预处理出来的整棵树的大小，减去
size[v]就是除以v为根的子树以外的结点数。
f[v]=f[u]+sz[1]-sz[v]*2
*/
const int M=2*N;
LL e[M],ne[M],idx;
LL ans;//答案 

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

//u:当前节点
//fath:父亲节点
//deep:当前深度 
void dfs(LL u,LL fath,LL deep) {
	sz[u]=w[u];//自己的点权
	for (LL i=h[u];i!=-1;i=ne[i]) {
		LL v=e[i];
		if (v==fath) {
			continue;
		}
		dfs(v,u,deep+1);
		sz[u]+=sz[v];//更新点权 
	}
	//更新f[1]
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
	ans=min(ans,f[u]);//更新答案 
}

void solve() {
	LL n;
	cin>>n;
	init(n);
	for (LL i=1;i<=n;i++) {
		LL u,v;
		cin>>w[i];//读取点权 
		cin>>u>>v;
		if (u) {
			//u 为左链接
			add(i,u);
			add(u,i);
		}
		if (v) {
			//v 为右链接
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
