//
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;
const LL MOD=32767;
const int MAXN=1e5+10;
LL a[MAXN];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);
	LL n;
	cin>>n;
	for (LL i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1, a+n+1);
	
	//求数列的gcd 
	for (LL i=2; i<=n; i++) {
		a[i]-=a[1];
	}
	LL d=a[2];
	for (LL i=3; i<=n; i++) {
		d=__gcd(d, a[i]);
	}
	
	if (d==0) {
		cout<<n<<"\n";
	} else {
		cout<<a[n]/d+1<<"\n";
	}
	return 0;
}

