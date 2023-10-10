//http://47.110.135.197/problem.php?id=5725
//http://acm.hdu.edu.cn/showproblem.php?pid=1166

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//Segment tree
const int MAXN=5e4+10;
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
	if (end<L||R<start) {
		return 0;
	} else if (L<=start&&end<=R) {
		return st[node];
	}
	int mid=(start+end)/2;
	int l_node=2*node;
	int r_node=2*node+1;
	int ret=query(l_node, start, mid, L, R);
	ret+=query(r_node, mid+1, end, L, R);
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
	int T;
	cin>>T;
	for (int j=1; j<=T; j++) {
		cout<<"Case "<<j<<":\n";

		int n;
		cin>>n;
		for (int i=1; i<=n; i++) {
			cin>>a[i];
		}
		build(1, 1, n);
		
		string op;
		while (cin>>op) {
			if (op=="End") {
				break;
			}
			int x,y;
			cin>>x>>y;
			if ("Query"==op) {
				cout<<query(1, 1, n, x, y)<<"\n";
			} else if ("Add"==op) {
				update(1, 1, n, x, a[x]+y);
			} else if ("Sub"==op) {
				update(1, 1, n, x, a[x]-y);
			}
		}
	}

	return 0;
}

