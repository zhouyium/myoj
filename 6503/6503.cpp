#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1E5+10;
LL h[N];
bool vis[N];
LL dis[N];
LL e[N], ne[N], w[N], idx;

void add(LL a, LL b, LL c) {
	e[idx]=b;
	w[idx]=c;
	ne[idx]=h[a];
	h[a]=idx++;
}

LL ans;

LL dfs(LL u, LL fa) {
	LL d1=0;//表示从当前点向下走的最大长度 
	LL d2=0;
	for (LL i=h[u]; i!=-1; i=ne[i]) {
		LL v=e[i];
		if (v==fa) {
			continue;
		}
		LL d=dfs(v,u)+w[i];
		if (d>=d1) {
			d2=d1;
			d1=d;
		} else if (d>d2) {
			d2=d;
		}
	}
	
	ans=max(ans, d1+d2);
	
	return d1;
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
	LL n;
	cin>>n;
	for (LL i=1; i<n; i++) {
		LL a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
		add(b,a,c);
	}
	
	dfs(1, -1);
	
	cout<<ans<<"\n";

	return 0;
}

