//4308: DP23 不相邻取数
//http://47.110.135.197/problem.php?id=4308
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=2e5+10;
LL a[N];
LL f[N][2];
/*
  f[i][0]: 不取a[i]的时候最大收益
    f[i][0]=max(f[i-1][1],f[i-1][0])
  f[i][1]: 取a[i]的最大收益
    f[i][1]=f[i-1][0]+a[i];
 */

void solve() {
	LL n;
	cin>>n;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}
	
	//初始化
	f[0][0]=0;
	f[0][1]=0;
	for(LL i=1;i<=n;i++){
		f[i][0]=max(f[i-1][0], f[i-1][1]);
		f[i][1]=f[i-1][0]+a[i];
	}
	
	cout<<max(f[n][0], f[n][1])<<"\n";
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
	LL n=10;
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
