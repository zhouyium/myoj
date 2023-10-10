#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=2e6+10;

//º∆À„phi[x] 
LL phi(LL x) {
	LL res=x;
	for (LL i=2;i*i<=x;i++) {
		if (x%i==0) {
			res=res/i*(i-1);
			while (x%i==0) {
				x/=i;
			}
		}
	}
	if (x>1) {
		res=res/x*(x-1);
	}
	return res;
}

void solve() {
	LL n;
	cin>>n;
	LL x=phi(n);
	cout<<n-x<<"\n";
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	//freopen("marathon.in", "r", stdin);
	//freopen("marathon.out", "w", stdout);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

