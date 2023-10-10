#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=5e2+10;
int a[MAXN][MAXN];
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=i; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	
	//ÄæÍÆ
	for (int i=n; i>=1; i--) {
		for (int j=1; j<=i; j++) {
			a[i-1][j]=a[i-1][j]+max(a[i][j], a[i][j+1]);
		}
	}
	
	printf("%d\n", a[1][1]);

	return 0;
}

