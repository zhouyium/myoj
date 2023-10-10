#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=1e5+10;
int st[MAXN*4];
int add[MAXN*4];

void push_down(int node, int start, int end) {
	if (add[node]) {
		int l_node=2*node;
		add[l_node]+=add[node];
		st [l_node]+=add[node]*start;
		
		int r_node=2*node+1;
		add[r_node]+=add[node];
		st [r_node]+=add[node]*end;
		
		add[node]=0;
	}
}

//[L, R] + c
void update(int node, int start, int end, int L, int R, int c) {
	if (L<=start&&end<=R) {
		add[node]+=c;
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
	st[node]=st[l_node]+st[r_node];
}

int query(int node, int start, int end, int L, int R) {
	if (L<=start&&end<=R) {
		return st[node];
	}
	int mid=(start+end)/2;
	push_down(node, mid-start+1, end-mid);
	int ret=0;
	if (L<=mid) {
		ret+=query(2*node, start, mid, L, R);
	}
	if (R>mid) {
		ret+=query(2*node+1, mid+1, end, L, R);
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
	while (cin>>n && n) {
		memset(add, 0, sizeof(add));
		memset(st,  0, sizeof(st));
		
		for (int i=1; i<=n; i++) {
			int x,y;
			cin>>x>>y;
			update(1,1,n,x,y,1);
		}
		for (int i=1; i<=n; i++) {
			cout<<query(1,1,n,i,i)<<" ";
		}
		cout<<"\n";
	}

	return 0;
}

