//
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;
const LL MOD=32767;
const int MAXN=1e6+10;

//x不含有2或者4 
bool check(LL x) {
	while (x) {
		LL t=x%10;
		if (2==t||4==t) {
			return false;
		}
		x/=10;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);
	LL n;
	cin>>n;
	
	LL ans=0;
	for (LL i=1; i<=n; i++) {
		for (LL j=1; j<=n; j++) {
			if (i==j) {
				continue;
			}
			LL k=n-i-j;
			//合法性检查 
			if (k>0&&k!=i&&k!=j&&check(i)&&check(j)&&check(k)) {
				ans++;
			}
		}
	}
	cout<<ans/6<<"\n";
	return 0;
}

