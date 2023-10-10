//4816: 匈牙利算法 —— 二分图的最大匹配
//http://47.110.135.197/problem.php?id=4816
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1E5+10;
LL h[N], match[N];
bool vis[N];
const int M=5e5+10;
LL e[M], ne[M], idx;

void add(LL a, LL b) {
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}

LL n1,n2,m;
bool find(LL u) {
	for (LL i=h[u]; i!=-1; i=ne[i]) {
		LL v=e[i];
		if (false==vis[v]) {
			vis[v]=true;
			if ((match[v]==0) || find(match[v])) {
				match[v]=u;
				match[u]=v;
				return true;
			}
		}
	}
	return false;
}

int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	memset(h, -1, sizeof h);
	
	cin>>n1>>n2>>m;
	for (LL i=1; i<=m; i++) {
		LL a,b;
		cin>>a>>b;
		add(a,b);
	}
	
	LL ans=0;
	for (LL i=1; i<=n1; i++) {
		memset(vis, false, sizeof vis);
		if (find(i)) {
			ans++;
		}
	}
	cout<<ans<<"\n";
	for (LL i=1; i<=n1; i++) {
		cout<<match[i]<<" ";
	}
	cout<<"\n";

	return 0;
}

