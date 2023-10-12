//http://47.110.135.197/problem.php?id=7489
//7489: 最小生成树 
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-7;

const int M=5e5+10;
struct NODE {
	LL u,v,w;
} a[M];

bool mycmp(const NODE &x, const NODE &y) {
	return x.w<y.w;
}

//DSU
const int N=2e5+10;
LL fa[N];
void init(LL n) {
	for (LL i=0; i<=n; i++) {
		fa[i]=-1;
	}
}

LL find(LL x) {
	if (fa[x]<0) {
		return x;
	}
	return fa[x] = find(fa[x]);
}

bool join(LL u,LL v) {
	u = find(u);
	v = find(v);
	if (u==v) {
		return false;
	}
	fa[u] += fa[v];
	fa[v] = u;
	return true;
}

void solve() {
	LL n,m;
	cin>>n>>m;
	for (LL i=1; i<=m; i++)	{
		cin>>a[i].u>>a[i].v>>a[i].w; 
	}
	sort(a+1, a+m+1, mycmp);
	
	init(n);
	LL res=0;
	LL cnt=0;
	for (LL i=1; i<=m; i++) {
		if (join(a[i].u, a[i].v)) {
			res += a[i].w;
			cnt++;
		}
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

