//http://47.110.135.197/problem.php?id=5823
//https://iai.sh.cn/problem/30

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=1e6+10;
int a[MAXN];

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);
	int n;
	cin>>n;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1, a+n+1);
	
	int ans=0;
	for (int i=1; i<=n; i++) {
		if (ans<=a[i]) {
			ans++;
		}
	}
	cout<<ans<<"\n";
	
	return 0;
}

