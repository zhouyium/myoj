//http://47.110.135.197/problem.php?id=5497
//5497: иол╗╫в III
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e3+4;
ll a[MAXN];
int main(){
	freopen("9.in", "r", stdin);
	freopen("9.out", "w", stdout);
	ll n,k;
	scanf("%lld %lld", &n,&k);
	
	a[1]=1;
	a[2]=2;
	a[3]=3;
	a[4]=0;
	for (int i=5; i<=n; i++) {
		int t=n-i;
		if (0!=t && (0==t%3 || 0==t%4)) {
			continue;
		}
		a[i]=a[i-1]+a[i-2]+a[i-3]+a[i-4];
	}
	
	for (int i=1; i<=k; i++) {
		int t;
		scanf("%d", &t);
		printf("%lld\n", a[t]);	
	}

	return 0;
}
