//8944: DP31 买卖股票的最好时机 II
//http://47.110.135.197/problem.php?id=8944

#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;
const LL MO=1e9+7;

const int N=1e5+10;
LL a[N];
/*
dp[i][0] 表示第 i 天交易完后手里没有股票的最大利润，
dp[i][1] 表示第 i 天交易完后手里持有一支股票的最大利润（i 从 0 开始）。  
 */
LL f[N][2];

void solve() {
	LL n;
	cin>>n;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}
	
	f[1][0] = 0;//当前没有持有股票的账户余额
	f[1][1] = -a[1];//当前持有股票的账户余额，因为买入股票了
	for(LL i=2;i<=n;i++){
		f[i][0] = max(f[i - 1][0], f[i - 1][1] + a[i]);
		f[i][1] = max(f[i - 1][1], f[i - 1][0] - a[i]);		
	}
	cout<<f[n][0]<<"\n";
}

int main() {
#if 1
	//提交到OJ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	LL T=1;
	//cin>>T;
	while(T--) {
		//cout<<i<<"\n";
		solve();
	}
#else
	int n=10;
	for(int i=0;i<n;i++){
		char in[16];
		sprintf(in, "%02d.in", i);
		char out[16];
		sprintf(out, "%02d.out", i);
		
		freopen(in, "r", stdin);
		freopen(out, "w", stdout);
		
		LL T=1;
		//cin>>T;
		while(T--) {
			//cout<<i<<"\n";
			solve();
		}
		
		fclose(stdin);
		fclose(stdout);
	}
#endif
	
	return 0;
}
