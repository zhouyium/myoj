//6676: DP43 最少的完全平方数
//http://47.110.135.197/problem.php?id=6676

#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;
const LL MO=1e9+7;

const int N=1e4+10;
LL f[N];

void solve() {
	LL n;
	cin>>n;
	
	for(LL i=0;i<=n;i++){
		f[i]=INF;
	}
	f[0]=0;
	for(LL i=1;i<=n;i++){
		for(LL j=1;j*j<=i;j++){
			f[i]=min(f[i],f[i-j*j]+1);
		}
	}
	
	cout<<f[n]<<"\n";
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
