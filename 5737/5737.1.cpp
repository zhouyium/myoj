#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//Segment Tree
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
	st[node]=st[l_node]+st[r_node];
}

void update(int node, int start, int end, int pos, int val) {
	if (start>=end) {
		a[pos]=val;
		st[node]=val;
		return;
	}
	int mid=(start+end)/2;
	int l_node=2*node;
	int r_node=2*node+1;
	if (pos<=mid) {
		update(l_node, start, mid, pos, val);
	} else {
		update(r_node, mid+1, end, pos, val);
	}
	st[node]=st[l_node]+st[r_node];
}

int query(int node, int start, int end, int L, int R) {
	
	if (L>end||R<start) {
		return 0;
	} else if (L<=start&&end<=R) {
		return st[node];
	} else if (start==end) {
		return st[node];
	}
	int mid=(start+end)/2;
	int l_node=2*node;
	int l_sum=query(l_node, start, mid, L, R);
	int r_node=2*node+1;
	int r_sum=query(r_node, mid+1, end, L, R);
	return l_sum+r_sum;
}
int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
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

