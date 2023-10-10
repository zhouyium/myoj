//http://47.110.135.197/problem.php?id=5768
//5768: 埃拉托斯特尼筛法判定素数

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=1e7+10;
bool vis[MAXN];
int  pri[MAXN];
void euler_sieve(ll n) {
	for (int i=2; i<=n; i++) {
		if (vis[i]==false) {
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
	int n,m;
	cin>>n>>m;
	euler_sieve(n);
	
	cout<<pri[0]<<"\n";
	for (int i=pri[0]-min(pri[0], m)+1; i<=pri[0]; i++) {
		cout<<pri[i]<<" ";
	}
	cout<<"\n";

	return 0;
}

