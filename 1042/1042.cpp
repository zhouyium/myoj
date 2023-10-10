#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1E3+50;
LL a[MAXN][MAXN];

void merge(LL n) {
	LL m=n/2;
	for (LL i=1; i<=m; i++) {
		for (LL j=1; j<=m; j++) {
			a[i][j+m]=a[i][j]+m; //由左上角得到右上角
			a[i+m][j]=a[i][j+m]; //由右上角得到左下角
			a[i+m][j+m]=a[i][j]; //由左上角得到右下角
		}
	}
}

void arrang(LL n) {
	if (n==1) {
		a[1][1]=1;
		return;
	}
	arrang(n/2);
	merge(n);
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("07.out", "w", stdout);
	LL n;
	cin>>n;
	n=pow(2, n);
	
	arrang(n);
	for (LL i=1; i<=n; i++) {
		for (LL j=1; j<=n; j++) {
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}

	return 0;
}

