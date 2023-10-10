//http://47.110.135.197/problem.php?id=5507
//5507: É½¹È
#include <bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;

const int N=1E6+10;
LL a[N];

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);
	LL n;
	cin>>n;
	for (LL i=1; i<=n; i++) {
		cin>>a[i];
	}

	a[0]=-9e18;
	a[n+1]=-9e18;

	LL cnt=0;
	LL maxx=a[0];
	for (LL i=1; i<=n; i++) {
		if (a[i]==a[i+1]) {
			continue;
		}
		if (maxx>a[i]&&a[i]<a[i+1]) {
			cnt++;
		}
		maxx=a[i];
	}
	cout<<cnt<<"\n";
	
	return 0;
}

