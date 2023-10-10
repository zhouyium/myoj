//http://47.110.135.197/problem.php?id=5735
//5735: 学习线段树 I —— 建立线段树

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=1e5+10;
int a[MAXN];
int seg[MAXN*4];

//从 l 到 r 建立线段树 
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
	
	build_tree(1, 1, n);
	
	for (int i=1; i<=4*n; i++) {
		cout<<seg[i]<<" ";
	}
	cout<<"\n";
	
	return 0;
}

