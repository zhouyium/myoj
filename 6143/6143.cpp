#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1E3+10;
LL dp[MAXN][MAXN];
LL path[MAXN][MAXN];//路径 
string a,b;

void print_lcs(LL n, LL m) {
	if (n==0&&m==0) {
		return;
	}
	if (path[n][m]==1) {
		print_lcs(n-1, m-1);
		cout<<a[n-1];		
	} else if (path[n][m]==2) {
		print_lcs(n-1, m);
		cout<<a[n-1];
	} else {
		print_lcs(n, m-1);
		cout<<b[m-1];		
	}
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	while (cin>>a>>b) {
		//LCS
		LL n=a.size();
		LL m=b.size();
		for (LL i=1; i<=n; i++) {
			path[i][0]=2;
		}
		for (LL i=1; i<=m; i++) {
			path[0][i]=3;
		}
		for (LL i=1; i<=n; i++) {
			for (LL j=1; j<=m; j++) {
				if (a[i-1]==b[j-1]) {
					dp[i][j]=dp[i-1][j-1]+1;
					path[i][j]=1;//来自左上
				} else if (dp[i-1][j] > dp[i][j-1]){ 
					dp[i][j]=dp[i-1][j];
					path[i][j]=2;//来自i-1
				} else {
					dp[i][j]=dp[i][j-1];
					path[i][j]=3;//来自j-1
				}
			}
		}
		
		//cout<<dp[n][m]<<"\n";
		print_lcs(n, m);
		cout<<"\n";		
	}
	
	
	return 0;
}

