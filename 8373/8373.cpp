#include <bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const LL MO=1e9+7;

const int N=1E2+10;
LL sum[N][N];//前缀和 
LL n;

//二维前缀和 + 暴力 
//时间复杂度 O(n^4) 
void calc(LL x,LL y,LL &res){
	for(LL i=x;i<=n;i++){
		for(LL j=y;j<=n;j++){
			LL t=sum[i][j]-sum[x-1][j]-sum[i][y-1]+sum[x-1][y-1];
			if(t>res){
				res=t;
			}
		}
	}
}

void solve() {
	cin>>n;
	
	//求出前缀和 
	for(LL i=1;i<=n;i++){
		for(LL j=1;j<=n;j++){
			LL t;
			cin>>t;
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+t;
		}
	}
	
	//暴力遍历
	LL maxx=-9e18;
	for(LL i=1;i<=n;i++){//行 
		for(LL j=1;j<=n;j++){//列 
			calc(i,j,maxx);
		}
	}
	cout<<maxx<<"\n";
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);
	LL T=1;
	//cin>>T;
	for (LL i=1; i<=T; i++) {
		//cout<<i<<"\n";
		solve();
	}

	return 0;
}


