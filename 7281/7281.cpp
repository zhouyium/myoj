//7281: AtCoder Educational DP Contest —— I - Coins
//http://47.110.135.197/problem.php?id=7281

#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;
const LL MO=1e9+7;

const int N=3e3+10;
double p[N];
double f[N][N];
/*
概率dp求概率一般是正推
f[i][j]表示第i个硬币时,有j个硬币是正面的概率
状态转移方程
  到第i-1个硬币时,有j-1个硬币正面,第i个硬币是正面. 
	  概率:f[i-1][j-1]*p[j]
  到第i-1个硬币时,有j个硬币正面,第i个硬币是反面. 
	  概率:f[i-1][j]*(1.0-p[j])
答案
  f[n][(n+1)/2]+f[n][(n+1)/2+1]+...+f[n][n]
 */
void solve() {
	LL n;
	cin>>n;
	for(LL i=1;i<=n;i++){
		cin>>p[i];
	}
	
	//初始化
	f[1][1]=p[1];
	f[1][0]=1-p[1];
	for(LL i=2;i<=n;i++){
		for(LL j=0;j<=i;j++){
			if(j==0){
				f[i][j]=f[i-1][j]*(1-p[i]);
				continue;
			}
			f[i][j]=f[i-1][j-1]*p[i]+f[i-1][j]*(1-p[i]);
		}
	}
	
	//计算答案
	double res=0;
	for(LL i=(n+1)/2; i<=n; i++){
		res+=f[n][i];
	}
	cout<<fixed<<setprecision(10)<<res<<"\n";
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
