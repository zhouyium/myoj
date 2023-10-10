//http://47.110.135.197/problem.php?id=5673
//5673: The Suspects

//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

const int MAXN=3e4+10;
int pa[MAXN];
int sa[MAXN];

int n;
void init() {
	for (int i=0; i<=n; i++) {
		pa[i]=i;
		sa[i]=1;
	}
}
int find(int x) {
	if (pa[x]!=x) {
		pa[x]=find(pa[x]);
	}
	return pa[x];
}
void join(int x, int y) {
	int px=find(x);
	int py=find(y);
	if (px!=py) {
		pa[py]=px;
		sa[px]+=sa[py];
	}
}

int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int m;
	while (cin>>n>>m) {
		if (n==0&&m==0) {
			break;
		}
		init();
		for (int i=1; i<=m; i++) {
			int K;
			cin>>K;
			int x,y;
			cin>>x;
			for (int j=2; j<=K; j++) {
				cin>>y;
				join(x,y);
			}
		}
		//查询0号所在的集合有多少人
		int px=find(0);
		cout<<sa[px]<<"\n";
	}

	return 0;
}

