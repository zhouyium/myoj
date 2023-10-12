//8946: DP33 买卖股票的最好时机 IV
//http://47.110.135.197/problem.php?id=8946

#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;
const LL MO=1e9+7;

const int N=1e3+10;
LL a[N];
/*
1是持有，0是未持有
dp[i][j][0]表示第i天交易了j次时不持有股票, 
dp[i][j][1]表示第i天交易了j次时持有股票  
 */
LL f[N][110][2];

void solve() {
	LL n,K;
	cin>>n>>K;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(LL j=0;j<=K+1;j++){
		f[1][j][0]=0;
		f[1][j][1]=-a[1];
	}
	for(LL i=2;i<=n;i++){
		for(LL j=0;j<=K;j++){
			if(j==0){
				//没有交易
				f[i][j][0]=f[i-1][j][0];
			}else{
				f[i][j][0]=max(f[i-1][j][0], f[i-1][j-1][1]+a[i]);
			}
			f[i][j][1]=max(f[i-1][j][0]-a[i], f[i-1][j][1]);
		}
	}

	//查找答案
	LL maxx=0;
	for(LL j=0;j<=K+1;j++){
		maxx=max(maxx, f[n][j][0]);		
	}
	cout<<maxx<<"\n";
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
	int n=20;
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
