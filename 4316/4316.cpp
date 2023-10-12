#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=1e5+10;
LL a[N];//现金
LL f[N];//抢劫前i个店铺时包括了i时的最大得利数

void solve() {
	LL n;
	cin>>n;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}
	
	f[0]=0;
	f[1]=a[1];//抢劫第1家 
	f[2]=a[2];//抢劫第2家 
	for(LL i=3;i<=n;i++){
		//抢劫第i家 
		//间隔一个或间隔两个再洗劫 
		f[i]=max(f[i-2],f[i-3])+a[i];
	}
	cout<<max(f[n],f[n-1])<<"\n";
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);
	int T=1;
	cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

