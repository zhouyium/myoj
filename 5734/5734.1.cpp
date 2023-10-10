#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//segment tree
const int MAXN=1e4+10;
int a[MAXN];
int st[MAXN*4];
int add[MAXN*4];

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

void push_down(int node, int L, int R) {
	if (add[node]) {
		int l_node=2*node;
		add[l_node]+=add[node];
		st [l_node]+=add[node]*L;
		int r_node=2*node+1;
		add[r_node]+=add[node];
		st [r_node]+=add[node]*R;
		add[node]=0;
	}
}

void update(int node, int start, int end, int L, int R, int c) {
	if (start>end||L>R) {
		return;
	} else if (L<=start&&end<=R) {
		add[node]+=c;
		st [node]+=c*(end-start+1);
		return;
	}
	int mid=(start+end)/2;
	push_down(node, mid-start+1, end-mid);
	int l_node=2*node;
	if (L<=mid) {
		update(l_node, start, mid, L, R, c);
	} 
	int r_node=2*node+1;
	if (R>mid) {
		update(r_node, mid+1, end, L, R, c);
	}
	st[node]=st[l_node]+st[r_node];
}

int query(int node, int start, int end, int L, int R) {
	if (start>end||L>R) {
		return 0;
	} else if (L<=start&&end<=R) {
		return st[node];
	}
	int mid=(start+end)/2;
	push_down(node, mid-start+1, end-mid);
	int ret=0;
	int l_node=2*node;
	if (L<=mid) {
		ret+=query(l_node, start, mid, L, R);
	}
	int r_node=2*node+1;
	if (R>mid) {
		ret+=query(r_node, mid+1, end, L, R);
	}
	return ret;
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
	build(1,1,n);
	int m;
	cin>>m;
	for (int i=1; i<=m; i++) {
		int x,y,c;
		cin>>x>>y>>c;
		update(1,1,n,x,y,c);

		for (int j=1; j<=n; j++) {
			query(1,1,n,j,j);
		}
		for (int j=1; j<=4*n; j++) {
			cout<<st[j]<<" ";
		}
		cout<<"\n";
	}

	return 0;
}

