//4528: 杨辉三角形
//http://47.110.135.197/problem.php?id=4528

#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;
const LL MO=1e9+7;

const int N=1e3+10;
LL f[N][N];

void solve() {
	LL n;
	cin>>n;
	
	f[1][1]=1;
	for(LL i=2;i<=n;i++){
		for(LL j=1;j<=i;j++){
			if(j==1||i==j){
				f[i][j]=1;
			}
			f[i][j]=f[i-1][j]+f[i-1][j-1];
		}
	}
	
	for(LL i=1;i<=n;i++){
		for(LL j=1;j<=i;j++){
			cout<<f[i][j]<<" ";
		}
		cout<<"\n";
	}
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
