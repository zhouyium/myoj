//http://47.110.135.197/problem.php?id=5737
//5737: 学习线段树 III —— 查询操作

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=1e4+10;
int a[MAXN];
int seg[MAXN*4];

void build(int node, int start, int end) {
	if (start>=end) {
		seg[node]=a[start];
		return;
	}
	int mid=(start+end)/2;
	int l_node=node*2;
	int r_node=node*2+1;
	build(l_node, start, mid);
	build(r_node, mid+1, end);
	seg[node]=seg[l_node]+seg[r_node];
}

void update(int node, int start, int end, int pos, int val) {
	if (start>=end) {
		a[pos]=val;
		seg[node]=val;
		return;
	}
	int mid=(start+end)/2;
	int l_node=node*2;
	int r_node=node*2+1;
	if (pos<=mid) {
		update(l_node, start, mid, pos, val);
	} else {
		update(r_node, mid+1, end, pos, val);
	}
	seg[node]=seg[l_node]+seg[r_node];
}

int query(int node, int start, int end, int L, int R) {
	//cout<<"start="<<start<<", end="<<end<<"\n";
	if (L>end||R<start) {
		return 0;
	} else if (L<=start && end<=R) {
		return seg[node];
	}
	int mid=(start+end)/2;
	int l_node=node*2;
	int r_node=node*2+1;
	int ret=0;
	if (L<=mid) {
		ret+=query(l_node, start, mid, L, R);
	}
	if (R>mid) {
		ret+=query(r_node, mid+1, end, L, R);
	}
	return ret;
	//int l_sum=query(l_node, start, mid, L, R);
	//int r_sum=query(r_node, mid+1, end, L, R);
	//return l_sum+r_sum;
}

int main() {
#if 0
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
	for (int i=1; i<=m; i++) {
		int L,R;
		cin>>L>>R;
		cout<<query(1, 1, n, L, R)<<"\n";
	}

	return 0;
}

