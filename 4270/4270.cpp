#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1E3+10;
const LL INF=0x3F3F3F3F;
LL a[MAXN][MAXN];
LL dp[MAXN];//表示城市v1到v10的最短距离
LL pre[MAXN];
 
int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	LL n;
	cin>>n;
	for (LL i=1; i<=n; i++) {
		for (LL j=1; j<=n; j++) {
			cin>>a[i][j];
		}
		dp[i]=INF;
	}
	
	dp[n]=0;
	for (LL i=n-1; i>=1; i--) {
		for (LL j=i+1; j<=n; j++) {
			if (a[i][j]>0 && dp[j]!=INF && dp[i]>dp[j]+a[i][j]) {
				dp[i]=a[i][j]+dp[j];
				pre[i]=j;
			}
		}
	}
	
	cout<<"minlong="<<dp[1]<<"\n";
	LL x=1;
	while (x!=0) {
		cout<<x<<" ";
		x=pre[x];
	}
	cout<<"\n";

	return 0;
}

