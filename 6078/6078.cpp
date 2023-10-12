//6078: DP27 跳跃游戏 II
//http://47.110.135.197/problem.php?id=6078

#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=1e5+10;
LL a[N];
LL f[N];
/*
f[i]: 走到第i位置获得的最大积分
  
 */

void solve() {
	memset(f, 0, sizeof f);
	
	LL n;
	cin>>n;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}

	f[1]=a[1];
	for(LL i=1;i<=n;i++){
		for(LL j=i+1; f[i] && j<=n && j<=i+a[i]; j++){
			f[j]=max(f[j], f[i]+a[j]);
		}
	}
	
	if(f[n]==0){
		cout<<"-1\n";
	}else{
		cout<<f[n]<<"\n";
	}
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
