//8951: DP53 取数游戏
//http://47.110.135.197/problem.php?id=8951

#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;
const LL MO=1e9+7;

const int N=1e3+10;
LL a[N], b[N];
LL f[N][N];
/*
  dp[l][r]: 表示左侧取 l 个，右侧取 r 个的最大值  
 */

void solve() {
	LL n;
	cin>>n;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}
	for(LL i=1;i<=n;i++){
		cin>>b[i];
	}
	
	for(LL i=0;i<=n;i++){
		for(LL j=0;j<=n;j++){
			f[i][j]=0;
		}
	}
	for(LL len=1;len<=n;len++){
		for(LL i=0;i<=len;i++){//起点
			LL r=len-i;//终点
			if(i>0){
				f[i][r]=f[i-1][r]+a[i]*b[len];
			}
			if(r>0){
				f[i][r]=max(f[i][r], f[i][r-1]+a[n-r+1]*b[len]);
			}
		}
	}
	
	LL maxx=-9e18;
	for(LL i=0;i<=n;i++){
		maxx=max(maxx, f[i][n-i]);
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
