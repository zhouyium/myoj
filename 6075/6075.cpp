#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=1e6+10;
LL a[N];
LL f[N][2];
/*
  f[i][0]: 不偷窃a[1]能偷窃到的最高总金额
    f[i][0]=max(f[i-1][0], f[i-2][0]+a[i]);
  f[i][1]: 不偷窃a[n]能偷窃到的最高总金额
    f[i][1]=max(f[i-1][1], f[i-2][1]+a[i]);
 */

void solve() {
	LL n;
	cin>>n;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}
	
	//第一个可能，第1家不偷
	f[1][0]=0;   //a[1]不偷
	f[2][0]=a[2];//a[2]偷
	for(LL i=3;i<=n;i++){
		f[i][0]=max(f[i-1][0], f[i-2][0]+a[i]);
	}
	//第二个可能，第n家不偷
	f[0][1]=0;
	f[1][1]=a[1];//a[1]偷
	for(LL i=2;i<n;i++){//最后一家不偷
		f[i][1]=max(f[i-1][1], f[i-2][1]+a[i]);
	}
	
	//找答案
	LL ans=0;
	for(LL i=1;i<=n;i++){
		LL t=max(f[i][0], f[i][1]);
		if(t>ans){
			ans=t;
		}
	}
	//cout<<ans<<"\n";
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
