//P3383 【模板】线性筛素数

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=1e6+10;
bool vis[MAXN];
int pri[MAXN];

void euler(ll n) {
	vis[1]=true;
	for (int i=2; i<=n; i++) {
		if (false==vis[i]) {
			pri[++pri[0]]=i;
		}
		for (int j=1; j<=pri[0]&&i*pri[j]<=n; j++) {
			vis[i*pri[j]]=true;
			if (i%pri[j]==0) {
				break;
			}
		}
	}
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);
	ll n, q;
	cin>>n>>q;
	euler(n);
	for (int i=1; i<=q; i++) {
		int k;
		cin>>k;
		cout<<pri[k]<<"\n";
	}

	return 0;
}

