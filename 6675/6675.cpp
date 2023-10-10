#include <bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const LL MO=1e9+7;

const int N=2E5+10;
LL f[N][2];
//f[i][0]  负数长度
//f[i][1]  正数长度

void solve() {
	LL n;
	cin>>n;
	
	LL res=0;
	LL x;
	cin>>x;
	if(x<0){
		f[1][0]=1;
	}else if(x>0){
		f[1][1]=1;
		res=1;
	}
	for(LL i=2;i<=n;i++){
		cin>>x;
		if(x>0){
			f[i][0]=f[i-1][0]>0?f[i-1][0]+1:0;
			f[i][1]=f[i-1][1]+1;
		}else if(x<0){
			f[i][0]=f[i-1][1]+1;
			f[i][1]=f[i-1][0]>0?f[i-1][0]+1:0;
		}else{
			f[i][0]=0;
			f[i][1]=0;
		}
		res=max(res,f[i][1]);
	}
	
	cout<<res<<"\n";
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("10.in", "r", stdin);
	//freopen("10.out", "w", stdout);
	LL T=1;
	//cin>>T;
	for (LL i=1; i<=T; i++) {
		//cout<<i<<"\n";
		solve();
	}

	return 0;
}


