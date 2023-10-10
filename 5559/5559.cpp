//http://47.110.135.197/problem.php?id=5559
//5559: ≤…“© II
 
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1E4+10;
LL w[MAXN], v[MAXN];
const int MAXF=1e7+10;
LL f[MAXF]; 

int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	freopen("02.in", "r", stdin);
	freopen("02.out", "w", stdout);
	LL n,W;
	cin>>W>>n;
	for (LL i=1; i<=n; i++) {
		cin>>w[i]>>v[i];
	}
	
	for (LL i=1; i<=n; i++) {
		for (LL j=w[i]; j<=W; j++) {
			f[j]=max(f[j], f[j-w[i]]+v[i]);
		}
	}
	
	cout<<f[W]<<"\n";

	return 0;
}

