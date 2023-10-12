//8945: DP31 买卖股票的最好时机 III
//http://47.110.135.197/problem.php?id=8945

#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;
const LL MO=1e9+7;

const int N=5e5+10;
LL a[N];
/*
  //f[i][0]表示到第i天为止没有买卖过股票的最大收益
  //f[i][1]表示到第i天为止买过一次股票还没有卖出的最大收益
  //f[i][2]表示到第i为止买卖过一次股票的最大收益
  //f[i][3]表示到第i天为止买了两次卖出一只的最大收益
  //f[i][4]表示到第i天为止买卖了两次股票的最大收益
 */
LL f[N][5];

void solve() {
	LL n;
	cin>>n;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(LL i=0;i<=4;i++){
		f[1][i]=-9e18;
	}
	f[1][0]=0;
	f[1][1]=-a[1];
	for(LL i=2;i<=n;i++){
		f[i][0]=f[i-1][0];
		f[i][1]=max(f[i-1][1],f[i-1][0]-a[i]);
		f[i][2]=max(f[i-1][2],f[i-1][1]+a[i]);
		f[i][3]=max(f[i-1][3],f[i-1][2]-a[i]);
		f[i][4]=max(f[i-1][4],f[i-1][3]+a[i]);
	}
	cout<<max(f[n][0], max(f[n][2], f[n][4]))<<"\n";
}

int main() {
#if 0
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
