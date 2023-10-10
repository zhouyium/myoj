//http://47.110.135.197/problem.php?id=5697
//5697: 和为K的子数组

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=2e4+10;
int a[MAXN];

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("10.in", "r", stdin);
	//freopen("10.out", "w", stdout);
	int n,K;
	cin>>n>>K;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
		a[i]+=a[i-1];
	}
	
	ll ans=0;
	unordered_map<int, int> hash;
	hash[0]=1;
	for (int i=1; i<=n; i++) {
		if (hash.count(a[i]-K)>0) {
			ans+=hash[a[i]-K];
		}
		hash[a[i]]++;
	}
	cout<<ans<<"\n";

	return 0;
}

