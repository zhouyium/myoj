#include <bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const LL MO=1e9+7;

const int N=1E3+10;
LL a[N][N];
LL f[N][N];//f[i][j]表示从(1,1)到达(i,j)的最小路径和
//dp[1][j] = dp[1][j-1]+a[1][j]
//dp[i][1] = dp[i-1][1] + a[i][1]
//dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + a[i][j]

void solve() {
	LL n,m;
	cin>>n>>m;
	for(LL i=1;i<=n;i++){
		for(LL j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	
	for(LL i=1;i<=n;i++){
		for(LL j=1;j<=m;j++){
			if(i==1&&j==1){
				f[i][j]=a[i][j];
			}else if(i==1){
				f[i][j]=f[i][j-1]+a[i][j];
			}else if(j==1){
				f[i][j]=f[i-1][j]+a[i][j];
			}else{
				f[i][j]=min(f[i-1][j],f[i][j-1])+a[i][j];
			}
		}
	}
	cout<<f[n][m]<<"\n";
}

int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	LL T=1;
	//cin>>T;
	for (LL i=1; i<=T; i++) {
		//cout<<i<<"\n";
		solve();
	}

	return 0;
}


