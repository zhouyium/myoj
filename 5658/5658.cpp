//http://47.110.135.197/problem.php?id=5658
//5658: Cutting a graph

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct OP {
	string op;
	int u;
	int v;
};

int n;
const int MAXN=5e4+10;
int fa[MAXN];
int sa[MAXN];

void init() {
	for (int i=0; i<=n; i++) {
		fa[i]=i;
		sa[i]=1;
	}
}
int find(int x) {
	if (x==fa[x]) {
		return x;
	}
	return find(fa[x]);
}
void join(int x, int y) {
	x=find(x);
	y=find(y);
	if (x==y) {
		return;
	}
	if (sa[x]>sa[y]) {
		swap(x, y);
	}
	fa[x]=y;
	sa[y]+=sa[x];
}
int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("9.in", "r", stdin);
	//freopen("9.out", "w", stdout);
	int m,K;
	cin>>n>>m>>K;
	init();
	for (int i=1; i<=m; i++) {
		int x, y;
		cin>>x>>y;
	}
	
	vector<OP> vs;//保存所有指令 
	for (int i=1; i<=K; i++) {
		OP t;
		cin>>t.op>>t.u>>t.v;
		vs.push_back(t);
	}
	
	vector<string> ans;
	while (vs.size()) {
		OP t=vs.back();
		if (t.op=="cut") {
			join(t.u, t.v);
		} else {
			int x=find(t.u);
			int y=find(t.v);
			if (x==y) {
				ans.push_back("YES");
			} else {
				ans.push_back("NO");
			}
		}
		vs.pop_back();
	}
	
	for (int i=ans.size()-1; i>=0; i--) {
		cout<<ans[i]<<"\n";
	}

	return 0;
}

