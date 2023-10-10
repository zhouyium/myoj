#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=5e2+10;
int a[MAXN][MAXN];
int f[MAXN];
int main() {
	//freopen("9.in", "r", stdin);
	//freopen("9.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=i; j++) {
			scanf("%d", &a[i][j]);
		}
	}

#if 1
	//倒序不需要处理边界 
	for (int i=n; i>=1; i--) {
		for (int j=i; j>=1; j--) {
			a[i][j]=a[i][j]+max(a[i+1][j], a[i+1][j+1]);
		}
	}
	printf("%d\n", a[1][1]);
#else
	//正序需要处理边界 
	int ans=0;	
	for (int i=2; i<=n; i++) {
		for (int j=1; j<=i; j++) {
			a[i][j]=a[i][j]+max(a[i-1][j], a[i-1][j-1]);
			ans=max(ans, a[i][j]);
		}
	}
	printf("%d\n", ans);
#endif

	return 0;
}
