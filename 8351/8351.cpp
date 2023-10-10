#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=2e6+10;
bool st[N];
LL primes[N],cnt;
LL phi[N];

void euler(LL n) {
	phi[1]=1;
	for (LL i=2;i<=n;i++) {
		if (st[i]==false) {
			primes[++cnt]=i;
			phi[i]=i-1;
		}
		//遍历所有的素数 
		for (LL j=1;primes[j]*i<=n;j++) {
			LL t=primes[j]*i;
			st[t]=true;
			if (i%primes[j]==0) {
				phi[t]=phi[i]*primes[j];
				break;
			}
			phi[t]=phi[i]*(primes[j]-1);
		}
	}
}

void solve() {
	LL n;
	cin>>n;
	for (LL i=1;i<=n;i++) {
		LL x;
		cin>>x;
		cout<<phi[x]<<"\n";
	}
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	freopen("09.in", "r", stdin);
	freopen("09.out", "w", stdout);
	euler(32768);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

