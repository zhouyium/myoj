#include <bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const LL MO=1e9+7;

const int N=1E6+10;
LL cost[N];
//从大到小分析 对于第 i 阶，到顶需要的花费  
// f[i] = cost[i] + min(f[i + 1] , f[i + 2])
//最后取 min(f[0] , f[1])
LL f[N]; 

void solve() {
	LL n;
	cin>>n;
	for(LL i=0;i<n;i++){
		cin>>cost[i];
	}
	
	if(n==1){
		cout<<cost[0]<<"\n";
		return;
	}

	//逆推
	f[n-1]=cost[n-1];
	f[n-2]=cost[n-2];
	for(LL i=n-3;i>=0;i--){
		f[i]=cost[i]+min(f[i+1], f[i+2]);
	}
	cout<<min(f[0],f[1])<<"\n";
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	freopen("09.in", "r", stdin);
	freopen("09.out", "w", stdout);
	LL T=1;
	//cin>>T;
	for (LL i=1; i<=T; i++) {
		//cout<<i<<"\n";
		solve();
	}

	return 0;
}


