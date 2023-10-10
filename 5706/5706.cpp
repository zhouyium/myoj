//http://47.110.135.197/problem.php?id=5706
//5706: �޸���·
//Kruskal�㷨����С������
 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=2e5+10;
//���鼯���� 
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
	if (fa[x]!=x) {
		fa[x]=find(fa[x]);
	}
	return fa[x];
}

//MST  Minimum Spanning Tree
const int MAXM=2e5+10;
struct EDGE {
	int x,y;//��������
	int w;//Ȩ�� 
} edge[MAXM];
bool mycmp(const EDGE &a, const EDGE &b) {
	//Ȩ�ش�С�������� 
	return a.w<=b.w;
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);
	int m;
	cin>>n>>m;
	init();
	for (int i=1; i<=m; i++) {
		cin>>edge[i].x>>edge[i].y>>edge[i].w;
	}
	sort(edge+1, edge+m+1, mycmp);
	
	int cnt=0;//�ϲ��Ĵ��� 
	int maxx=0;//���Ȩ�� 
	for (int i=1; i<=m; i++) {
		int x=find(edge[i].x);
		int y=find(edge[i].y);
		if (x==y) {
			continue;
		}
		
		fa[y]=x;
		maxx=max(maxx, edge[i].w);
		cnt++;
	}
	
	if (cnt<n-1) {
		//����ͨ
		cout<<"-1\n"; 
	} else {
		cout<<maxx<<"\n";
	}

	return 0;
}

