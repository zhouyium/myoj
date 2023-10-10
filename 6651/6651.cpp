#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=1e5+10;
LL a[N];
LL fa[N];//
LL fb[N];

void solve() {
	LL n;
	cin>>n;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}
	
	//
	fa[1]=a[1];
	for(LL i=2;i<=n;i++){
		fa[i]=max(a[i],fa[i-1]+a[i]);
	}
	//求到位置i左边的最大序列
	for(LL i=2;i<=n;i++){
		fa[i]=max(fa[i],fa[i-1]);
	}
	//
	fb[n]=a[n];
	for(LL i=n-1;i>=1;i--){
		fb[i]=max(a[i],fb[i+1]+a[i]);
	}
	//求到位置i右边的最大序列
	for(LL i=n-1;i>=0;i--){
		fb[i]=max(fb[i],fb[i+1]);
	}
	
	//找不同位置i的d(A)值，求出最大值
	LL maxx=-9e18;
	for(LL i=1;i<n;i++){
		maxx=max(maxx,fa[i]+fb[i+1]);
	}
	cout<<maxx<<"\n";
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	freopen("02.in", "r", stdin);
	freopen("02.out", "w", stdout);

	int T=1;
	cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

