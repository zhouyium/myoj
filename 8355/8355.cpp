#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=2e6+10;

struct NODE {
	LL x,p;
	bool operator<(const NODE& c) const {
		return x>c.x;
	}
} now;
priority_queue<NODE> pi;

//分解因数法计算phi(x) 
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
	for (LL i=1;i*i<=n;i++) {
		if (n%i==0) {
			now.x=n/i;
			now.p=phi(i);
			pi.push(now);
			//看看是否还有一个因子
			if (i*i!=n) {
				now.x=i;
				now.p=phi(n/i);
				pi.push(now);
			}
		}
	}
	
	while (pi.size()) {
		now=pi.top();
		pi.pop();
		cout<<now.x<<" "<<now.p<<"\n";
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

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}
