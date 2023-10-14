//8949: DP40 小红取数
//http://47.110.135.197/problem.php?id=8949

#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;
const LL MO=1e9+7;

const int N=1e3+10;
LL a[N];
LL f[N][N];
/*
f[i][j]表示前i个数中除以k的余数为j的当前最大和。
  0个数时，最大和必为0，所以 f[0][0]=0
  如果前一个状态余数为j，则更新当前余数为(j+arr[i])%k的情况，
  要么从余数为j的状态转化过来，要么前一个状态余数也是(j+arr[i])%k，即不选择当前元素。
  f[i][(j+a[i])%K]=max(f[i-1][j]+a[i], f[i-1][(j+a[i])%K]);
 */

void solve() {
	LL n,K;
	cin>>n>>K;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(LL i=0;i<=n;i++){
		for(LL j=0;j<K;j++){
			f[i][j]=-9e18;
		}
	}
	f[0][0]=0;
	for(LL i=1;i<=n;i++){
		for(LL j=0;j<K;j++){
			LL t=(j+a[i])%K;
			f[i][t]=max(f[i-1][j]+a[i], f[i-1][t]);
		}
	}
	
	if(f[n][0]<=0){
		f[n][0]=-1;
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
	for(int i=0;i<=n;i++){
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
