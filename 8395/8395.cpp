#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=1e7+10;
bool vis[N];
LL primes[N], cnt;

void euler(LL n) {
	for (LL i=2;i<=n;i++) {
		if (vis[i]==false) {
			primes[++cnt]=i;
		}
		for (LL j=1;j<=cnt && primes[j]*i<=n;j++) {
			vis[primes[j]*i]=true;
			if (i%primes[j]==0) {
				break;
			}
		}
	}
}

unordered_map<LL, PLL> mp;

void solve() {
	LL n;
	cin>>n;
	if (mp.count(n)) {
		PLL t=mp[n];
		cout<<t.first<<" "<<t.second<<"\n";
		return;
	}

	for (LL i=1;i<=cnt;i++) {
		//p=primes[i]
		LL p=primes[i];
		LL q=n/(p*p);
		if (p*p*q==n) {
			cout<<p<<" "<<q<<"\n";
			mp[n]={p,q};
			break;
		}
		//q=primes[i]
		q=primes[i];
		p=sqrt(n/q);
		if (p*p*q==n) {
			cout<<p<<" "<<q<<"\n";
			mp[n]={p,q};
			break;
		}
	}
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	//freopen("marathon.in", "r", stdin);
	//freopen("marathon.out", "w", stdout);
	euler(1e7);

	int T=1;
	cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}
