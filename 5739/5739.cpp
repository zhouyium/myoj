//http://47.110.135.197/problem.php?id=5739
//5739: ѧϰ�߶��� V ���� ������ֵ��ѯ���⣨RMQ��֮��Сֵ

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=1e4+10;
int a[MAXN];
int st[MAXN*4];

void build(int node, int start, int end) {
	if (start>=end) {
		st[node]=a[end];
		return;
	}
	int mid=(start+end)/2;
	int l_node=2*node;
	build(l_node, start, mid);
	int r_node=2*node+1;
	build(r_node, mid+1, end);
	st[node]=min(st[l_node], st[r_node]);
}

int query(int node, int start, int end, int L, int R) {
	if (L>end||R<start) {
		return 0;
	} else if (start>=L&&end<=R) {
		return st[node];
	}
	int mid=(start+end)/2;
	int l_min=1e5;
	if (L<=mid) {
		l_min=query(2*node, start, mid, L, R);
	}
	int r_min=1e5;
	if (R>mid) {
		r_min=query(2*node+1, mid+1, end, L, R);
	}
	return min(l_min, r_min);
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);
	int n;
	cin>>n;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
	}
	build(1, 1, n);
	int m;
	cin>>m;
	for (int i=1; i<=m; i++)  {
		int L,R;
		cin>>L>>R;
		cout<<query(1, 1, n, L, R)<<"\n";
	}
	
	return 0;
}

