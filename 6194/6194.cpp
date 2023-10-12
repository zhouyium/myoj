//http://47.110.135.197/problem.php?id=6194
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;

const int MAXN=1e4+10;
vector<LL> ne[MAXN];
LL n;
LL ans;
bool wifi[MAXN];

void dfs(LL u, LL fa) {
	//cout<<"u="<<u<<" fa="<<fa<<"\n";
	bool flag=false;
	for (LL i=0; i<ne[u].size(); i++) {
		LL v=ne[u][i];
		if (v==fa) {
			continue;
		}
		dfs(v, u);
		if (wifi[v]) {
			flag=true;
		}
	}
	if (false==flag && false==wifi[u] && false==wifi[fa]) {
		//cout<<"fa="<<fa<<"\n";
		wifi[fa]=true;
		ans++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);
	
	cin>>n;
	for (LL i=1; i<n; i++) {
		LL u,v;
		cin>>u>>v;
		ne[u].push_back(v);
		ne[v].push_back(u);
	}
	
	dfs(1, 0);
	cout<<ans<<"\n";
	
	return 0;
}

