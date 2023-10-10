#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=5e4+10;
int a[MAXN];

int main() {
	freopen("10.in", "r", stdin);
	freopen("10.out", "w", stdout);
    int n,m;
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
        a[i]=a[i]+a[i-1];
    }
    
    for (int i=1; i<=m; i++) {
        int x,y;
        scanf("%d%d", &x, &y);

        int ans=a[n]-a[y]+a[x-1];
        printf("%d\n", ans);
    }

	return 0;
} 

