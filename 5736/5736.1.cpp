#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=1e4+10;
int a[MAXN];
int seg[MAXN*4];

void build(int node, int l, int r) {
	if (l>=r) {
		seg[node]=a[l];
		return;
	}
	int mid=(l+r)/2;
	int l_node=node*2;
	int r_node=node*2+1;
	build(l_node, l, mid);
	build(r_node, mid+1, r);
	seg[node]=seg[l_node]+seg[r_node]; 
}

void update(int node, int l, int r, int pos, int val) {
	if (l>=r) {
		a[pos]=val;
		seg[node]=val;
		return;
	}
	int mid=(l+r)/2;
	int l_node=node*2;
	int r_node=node*2+1;
	if (pos<=mid) {
		update(l_node, l, mid, pos, val);
	} else {
		update(r_node, mid+1, r, pos, val);
	}
	seg[node]=seg[l_node]+seg[r_node];
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
		int pos, val;
		cin>>pos>>val;
		update(1, 1, n, pos, val);
		
		for (int j=1; j<=4*n; j++) {
			cout<<seg[j]<<" ";
		}
		cout<<"\n";
	}

	return 0;
}

