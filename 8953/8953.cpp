//8953: DP55 二叉树中的最大路径和
//http://47.110.135.197/problem.php?id=8953

#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;
const LL MO=1e9+7;

const int N=1e5+10;
LL h[N];
LL a[N];
LL f[N];
/*
f[i]: 以编号为i的节点最大路径和  
 */
const int M=2*N;
LL e[M], ne[M], idx;

void init(LL n){
	for(LL i=0;i<=n;i++){
		h[i]=-1;
		f[i]=0;
	}
	idx=0;
}

void add(LL a,LL b){
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}

void dfs(LL u, LL fa){
	f[u]=max(f[u], f[u]+a[u]);
	for(LL i=h[u];i!=-1;i=ne[i]){
		LL v=e[i];
		if(v!=fa){
			dfs(v, u);
			f[u]=max(f[u], f[u]+a[u]);
		}
	}
}

void solve() {
	LL n;
	cin>>n;
	init(n);
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}
	for(LL i=1;i<=n;i++){
		LL x;
		cin>>x;
		add(i,x);
		add(x,i);
	}
	
	dfs(1, -1);
	
	LL maxx=0;
	for(LL i=1;i<=n;i++){
		maxx=max(maxx, f[i]);
	}
	cout<<maxx<<"\n";
}

int main() {
#if 1
	//提交到OJ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	LL T=1;
	//cin>>T;
	while(T--) {
		//cout<<i<<"\n";
		solve();
	}
#else
	int n=20;
	for(int i=0;i<n;i++){
		char in[16];
		sprintf(in, "%02d.in", i);
		char out[16];
		sprintf(out, "%02d.out", i);
		
		freopen(in, "r", stdin);
		freopen(out, "w", stdout);
		
		LL T=1;
		//cin>>T;
		while(T--) {
			//cout<<i<<"\n";
			solve();
		}
		
		fclose(stdin);
		fclose(stdout);
	}
#endif
	
	return 0;
}
