//http://47.110.135.197/problem.php?id=5675
//5675: ≈Û”—»¶

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e4+10; 
int fa[MAXN];
int sa[MAXN];
int n;
void init() {
	for (int i=0; i<=n; i++) {
		fa[i]=i;
		sa[i]=1;
	}
}
int find(int x) {
	if (x!=fa[x]) {
		fa[x]=find(fa[x]);
	}
	return fa[x];
}
void join(int x, int y) {
	x=find(x);
	y=find(y);
	if (x==y) {
		return;
	}
	if (sa[x]<sa[y]) {
		swap(x, y);
	}
	fa[y]=x;
	sa[x]+=sa[y];
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	freopen("9.in", "r", stdin);
	freopen("9.out", "w", stdout);
	cin>>n;
	init();
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			int t;
			cin>>t;
			if (1==t) {
				join(i, j);
			}
		}
	}
	
	int ans=0;
	for (int i=1; i<=n; i++) {
		if (i==find(i)) {
			ans++;
		}
	}
	cout<<ans<<"\n";

	return 0;
}

