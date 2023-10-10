#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
int a[MAXN];
int b[MAXN];//差分数组 
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		b[i]=a[i]-a[i-1];//求差分 
	}
	
	for (int i=1; i<=n; i++) {
		printf("%d ", b[i]);
	}
	printf("\n");

	return 0;
}

