//5562: DP44 兑换零钱
//http://47.110.135.197/problem.php?id=5562

#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;
const LL MO=1e9+7;

const int N=1e2+10;
LL w[N];//重量
const int F=5e5+10;
LL f[F];
/*
  完全背包
  f_j 表示第 i 种钱下，容量为 j 的背包的方案数  
 */

void solve() {
	LL n,W;
	cin>>n>>W;
	for(LL i=1;i<=n;i++){
		cin>>w[i];
	}
	
	for(LL i=0;i<=W;i++){
		f[i]=INF;
	}
	f[0]=0;
	for(LL i=1;i<=n;i++){
		for(LL j=w[i];j<=W;j++){
			f[j]=min(f[j], f[j-w[i]]+1);
		}
	}
	
	if(f[W]==INF){
		f[W]=-1;
	}
	cout<<f[W]<<"\n";
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
