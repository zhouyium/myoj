#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=1e8+10;
bool vis[MAXN];
int pri[MAXN]; 

void euler_seive(ll n) {
	vis[1]=true;
	for (ll i=2; i<=n; i++) {
		if (vis[i]==false) {
			pri[++pri[0]]=i;
		}
		for (ll j=1; j<=pri[0]&&i*pri[j]<=n; j++) {
			vis[i*pri[j]]=true;
			if (i%pri[j]==0) {
				break;
			}
		}
	}
}

int main() {
	int n,q;
	cin>>n>>q;
	euler_seive(n);
	while (q--) {
		int k;
		cin>>k;
		cout<<pri[k]<<"\n";
	}
	return 0;
}
