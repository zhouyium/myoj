#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1E3+10;
LL dp[MAXN][MAXN];
char path[MAXN];//Â·¾¶ 
string a,b;

void print_lcs(LL n, LL m) {
	if (n==0 || m==0) {
		return;
	}
	if (a[n]==b[m]) {
		print_lcs(n-1, m-1);
		cout<<a[n-1];
	} else if (dp[n][m+1]>dp[n+1][m]) {
		print_lcs(n-1, m);
		cout<<a[n-1];
	} else {
		print_lcs(n, m-1);
		cout<<b[m-1];		
	} 
}

int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	
	cin>>a>>b;
	
	//LCS
	LL n=a.size();
	LL m=b.size();
	for (LL i=0; i<n; i++) {
		for (LL j=0; j<m; j++) {
			if (a[i]==b[j]) {
				dp[i+1][j+1]=dp[i][j]+1;
			} else {
				dp[i+1][j+1]=max(dp[i+1][j], dp[i][j+1]);
			}
		}
	}
	
	print_lcs(n-1, m-1);
	
	LL cnt=0;
	for (LL i=n-1, j=m-1; i>=0 && j>=0;) {
		if (a[i]==b[j]) {
			path[++cnt]=a[i];
			i--;
			j--;
		} else {
			if (dp[i][j+1]>dp[i+1][j]) {
				--i;
			} else {
				--j;
			}
		}
	}

	for (LL i=cnt; i>=1; i--) {
		cout<<path[i];
	}
	cout<<"\n";
	
	return 0;
}

