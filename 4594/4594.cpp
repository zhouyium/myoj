#include <bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const LL MO=1e9+7;

const int N=1E6+10;
struct TREE{
	LL lson;//×ó¶ù×Ó 
	LL rson;//ÓÒ¶ù×Ó 
} tr[N];

//ÏÈÐò ¸ú×óÓÒ 
void preorder(LL u) {
	cout<<u<<" ";
	if (tr[u].lson) {
		preorder(tr[u].lson);
	}
	if (tr[u].rson) {
		preorder(tr[u].rson);
	}
}

//ÖÐÐò  ×ó¸úÓÒ
void inorder(LL u) {
	if (tr[u].lson) {
		inorder(tr[u].lson);
	}
	cout<<u<<" ";
	if (tr[u].rson) {
		inorder(tr[u].rson);
	}
}

//ºóÐò  ×óÓÒ¸ú
void postorder(LL u) {
	if (tr[u].lson) {
		postorder(tr[u].lson);
	}
	if (tr[u].rson) {
		postorder(tr[u].rson);
	}
	cout<<u<<" ";
}

void solve() {
	LL n;
	cin>>n;
	for (LL i=1;i<=n;i++) {
		cin>>tr[i].lson>>tr[i].rson;
	}
	
	preorder(1);
	cout<<"\n";
	inorder(1);
	cout<<"\n";
	postorder(1);
	cout<<"\n";
}

int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	LL T=1;
	//cin>>T;
	for (LL i=1; i<=T; i++) {
		//cout<<i<<"\n";
		solve();
	}

	return 0;
}


