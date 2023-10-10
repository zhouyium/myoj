//6260  图论入门
//http://47.110.135.197/problem.php?id=6260

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1E3+10;
LL a[MAXN][MAXN];

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	LL n,T;
	cin>>n>>T;
	LL tot=0;
	for (LL i=1; i<=n; i++) {
		for (LL j=1; j<=n; j++) {
			cin>>a[i][j];
			if (a[i][j]!=0) {
				tot++;
			}
		}
	}

	cout<<tot<<"\n";
	while (T--) {
		LL m;
		cin>>m;
		
		//出度
		LL deg_out=0;
		for (LL i=1; i<=n; i++) {
			if (a[m][i]!=0) {
				deg_out++;
			}
		}
		//入度
		LL deg_in=0;
		for (LL i=1; i<=n; i++) {
			if (a[i][m]!=0) {
				deg_in++;
			}
		}
		cout<<m<<" "<<deg_out<<" "<<deg_in<<"\n";
	}

	return 0;
}

