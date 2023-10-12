#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=4e4+10;
LL a[N]; 

bool mycmp(LL x,LL y) {
	return x>y;
}

void solve() {
	LL n,m;
	cin>>n>>m;
	LL cnt=0;
	unordered_map<LL,LL> mp;
	for (LL i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,mycmp);
	LL res=0;
	LL sum=0;
	for (LL i=1;i<=n;i++) {
		if (sum+a[i]<=m) {
			sum+=a[i];
			res+=a[i]*a[i]*a[i];
		}
	}
	cout<<res<<"\n";
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	freopen("07.in", "r", stdin);
	freopen("07.out", "w", stdout);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

