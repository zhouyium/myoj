#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=2e6+10;
LL a[N];
LL b[N];

void solve() {
    LL n;
    cin>>n;
    for (LL i=1;i<=n;i++) {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (LL i=2;i<n;i+=2) {
        swap(a[i],a[i+1]);
    }
    for (LL i=1;i<=n;i++) {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);

	freopen("03.in", "r", stdin);
	freopen("03.out", "w", stdout);

	int T=1;
	cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

