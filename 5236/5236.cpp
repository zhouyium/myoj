//http://47.110.135.197/problem.php?id=5236
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
int a[MAXN];

int num;
//>= min
bool check1(int mid) {
	return a[mid]>=num;
}
int bsearch1(int l, int r) {
	int mid;
	while (l<r) {
		mid=(l+r)/2;
		if (check1(mid)) {
			r=mid;
		} else {
			l=mid+1;
		}
	}
	return l;
}

//<= max
bool check2(int mid) {
	return a[mid]<=num;
}
int bsearch2(int l, int r) {
	int mid;
	while (l<r) {
		mid=(l+r+1)/2;
		if (check2(mid)) {
			l=mid;
		} else {
			r=mid-1;
		}
	}
	return l;
}

int main() {
	freopen("5.in", "r", stdin);
	freopen("5.out", "w", stdout);
	int n,q;
	scanf("%d%d", &n, &q);
	for (int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i=1; i<=q; i++) {
		scanf("%d", &num);
		
		int wz1=bsearch1(1, n);
		if (a[wz1]==num) {
			int wz2=bsearch2(1, n);
			printf("%d %d\n", wz1-1, wz2-1);
		} else {
			printf("-1 -1\n");
		}
	}

	return 0;
}

