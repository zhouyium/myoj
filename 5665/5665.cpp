#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
int a[MAXN];
int main() {
	//freopen("8.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int n;
	ll s;
	scanf("%d%lld", &n, &s);
	for (int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		//a[i]=a[i-1]+a[i];
	}
	
	int ans=0;
	ll  sum=0;
	//从i到j之间为满足条件的sum 
	for (int i=1,j=1; i<=n; i++) {
		sum+=a[i];
		while (sum>s) {
			sum-=a[j];
			j++;
		}
		ans=max(ans, i-j+1);
	}

	printf("%d\n", ans);

	return 0;
}

