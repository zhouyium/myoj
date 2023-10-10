//http://47.110.135.197/problem.php?id=6126
//6126: K±¶Çø¼ä
#include <bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL, LL>;
const LL MOD=32767;
const int MAXN=1e5+10;
LL a[MAXN];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("09.in", "r", stdin);
	freopen("09.out", "w", stdout);
	LL n,K;
	cin>>n>>K;
	LL sum=0;
	LL ans=0;
	a[0]=1;
	for (LL i=1; i<=n; i++) {
		LL x;
		cin>>x;
		sum=(sum+x)%K;
		ans += a[sum];
		a[sum]++;
	}
	
	cout<<ans<<"\n";
	
	return 0;
}

