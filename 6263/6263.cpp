//6263: 子树的结点个数
//http://47.110.135.197/problem.php?id=6263

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1E3+10;
vector<LL> child[MAXN];

//u 节点编号 
LL dfs(LL u) {
	LL cnt=1;
	for (LL i=0; i<child[u].size(); i++) {
		cnt += dfs(child[u][i]);
	}
	return cnt; 
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	LL n;
	cin>>n;
	for (LL i=1; i<n; i++) {
		LL a,b;
		cin>>a>>b;
		child[a].push_back(b);
	}
	
	for (LL i=1; i<=n; i++) {
		cout<<dfs(i)<<" ";
	}
	cout<<"\n";

	return 0;
}

