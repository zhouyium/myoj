//http://47.110.135.197/problem.php?id=5752
//https://www.51nod.com/Challenge/Problem.html#problemId=3070
//5752: 线段树练习 1

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=1e5+10;
int a[MAXN];
int st[MAXN*4];
int ad[MAXN*4];
struct NODE {
	int lSum;//计算区间l和区间r中，以l为左端点的最大子段和lSum
	int rSum;//计算区间l和区间r中，以r为右端点的最大子段和rSum
	int mSum;//区间l和r上的最大子段和
	int iSum;//区间元素的总和
};
void push_up(int node, ) 
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
	st[node]=max(st[l_node],st[r_node]);
}

void push_down(int node, int L, int R) {
	if (ad[node]) {
		int l_node=2*node;
		ad[l_node]+=ad[node];
		st[l_node]+=ad[node]*L;
		int r_node=2*node+1;
		ad[r_node]+=ad[node];
		st[r_node]+=ad[node]*R;
		ad[node]   =0;
	}
}

void update(int node, int start, int end, int L, int R, int c) {
	if (start>end||L>R) {
		return;
	} else if (L<=start&&end<=R) {
		ad[node]+=c;
		st[node]+=c*(end-start+1);
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
	st[node]=max(st[l_node],st[r_node]);
}

int query(int node, int start, int end, int L, int R) {
	if (start>end||L>R) {
		return 0;
	} else if (L<=start&&end<=R) {
		return st[node];
	}
	int mid=(start+end)/2;
	push_down(node, mid-start+1, end-mid);
	int l_ret=INT_MIN;
	int l_node=2*node;
	if (L<=mid) {
		l_ret=query(l_node, start, mid, L, R);
	}
	int r_ret=INT_MIN;
	int r_node=2*node+1;
	if (R>mid) {
		r_ret=query(r_node, mid+1, end, L, R);
	}
	return max(l_ret, r_ret);
}

int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
	}
	build(1,1,n);
	
	for (int i=1; i<=m; i++) {
		int x,y;
		cin>>x>>y;
		cout<<query(1,1,n,x,y)<<"\n";
	}

	return 0;
}

