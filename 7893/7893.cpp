#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=1e5+10;
double a[N], b[N];

void solve() {
	LL n;
	cin>>n;
	for (LL i=1; i<=n; i++) {
		cin>>a[i]>>b[i];
	}
	
	double sum=0;
	for (LL i=1; i<=n; i++) {
		sum+=a[i]/b[i];
	}
	sum/=2;
	
	double ans=0;
	for (LL i=1; sum; i++) {
		ans+=min(a[i], sum*b[i]);
		sum-=min(a[i]/b[i], sum);
	}
	cout<<fixed<<setprecision(6)<<ans<<"\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
	
	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

