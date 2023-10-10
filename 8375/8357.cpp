//http://47.110.135.197/problem.php?id=8375
//8375: DP12 龙与地下城游戏问题
#include <bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const LL MO=1e9+7;

const int N=1E3+10;
LL a[N][N];
LL f[N][N];
/*
f[i][j]: a[i][j]a[n][m]（终点）所需的最少初始血量
解：f[1][1] 
*/

void solve() {
	LL n,m;
	cin>>n>>m;
	for(LL i=1;i<=n;i++){
		for(LL j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	
	//初始化
	f[n][m]=max(1-a[n][m], 1ll);
	for(LL i=n-1;i>=1;i--){
		f[i][m]=max(f[i+1][m]-a[i][m], 1ll);
	}
	for(LL j=m-1;j>=1;j--){
		f[n][j]=max(f[n][j+1]-a[n][j], 1ll);
	}
	
	//逆推 
	for(LL i=n-1;i>=1;i--){
		for(LL j=m-1;j>=1;j--){
			f[i][j]=min(f[i][j+1], f[i+1][j])-a[i][j];
			f[i][j]=max(f[i][j], 1ll);
		}
	}
	
	cout<<f[1][1]<<"\n";
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("17.in", "r", stdin);
	//freopen("17.out", "w", stdout);
	LL T=1;
	//cin>>T;
	for (LL i=1; i<=T; i++) {
		//cout<<i<<"\n";
		solve();
	}

	return 0;
}
