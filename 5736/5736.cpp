//http://47.110.135.197/problem.php?id=5736
//5736: 学习线段树 II —— 单点修改

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=1e4+10;
int a[MAXN];
int seg[4*MAXN];

void build_tree(int node, int l, int r) {
	if (l>=r) {
		seg[node]=a[l];
		return;
	}
	int mid=(l+r)/2;
	int l_node = 2*node;
	int r_node = 2*node+1;
	build_tree(l_node, l, mid);
	build_tree(r_node, mid+1, r);
	seg[node]=seg[l_node]+seg[r_node];
}

void update(int node, int l, int r, int pos, int val) {
	if (l>=r) {
		a[pos]=val;
		seg[node]=val;
		return;
	}
	int mid=(l+r)/2;
	if (pos<=mid) {
		update(node*2, l, mid, pos, val);
	} else {
		update(node*2+1, mid+1, r, pos, val);
	}
	seg[node]=seg[node*2]+seg[node*2+1];
}

void print(int n) {
	for (int j=1; j<=4*n; j++) {
		cout<<seg[j]<<" ";
	}
	cout<<"\n";
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	freopen("04.in", "r", stdin);
	freopen("04.out", "w", stdout);
	int n;
	cin>>n;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
	}
	build_tree(1, 1, n);
	//print(n); 
	
	int m;
	cin>>m;
	for (int i=1; i<=m; i++) {
		int pos, val;
		cin>>pos>>val;
		update(1, 1, n, pos, val);
		
		print(n);
	}

	return 0;
}

