//http://47.110.135.197/problem.php?id=5349
//5349: Disjoint Sets Union II

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=3e5+10;
int fa[MAXN];
int sa[MAXN];
int mina[MAXN];//最小值 
int maxa[MAXN];//最大值 
int n;
void init() {
	for (int i=0; i<=n; i++) {
		fa[i]=i;
		sa[i]=1;
		mina[i]=i;
		maxa[i]=i;
	}
}
int find(int x) {
	if (fa[x]!=x) {
		fa[x]=find(fa[x]);
	}
	return fa[x];
}
void join(int x, int y) {
	int px=find(x);
	int py=find(y);
	if (px!=py) {
		fa[py]=px;
		sa[px]+=sa[py];
		mina[px]=min(mina[px], mina[py]);
		maxa[px]=max(maxa[px], maxa[py]);
	}
}
int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("9.in", "r", stdin);
	//freopen("9.out", "w", stdout);
	int m;
	cin>>n>>m;
	init();
	for (int i=1; i<=m; i++) {
		string op;
		cin>>op;
		if (op=="union") {
			int x,y;
			cin>>x>>y;
			join(x,y);
		} else if (op=="get") {
			int x;
			cin>>x;
			
			int px=find(x);
			cout<<mina[px]<<" "<<maxa[px]<<" "<<sa[px]<<"\n";
		}
	}

	return 0;
}

