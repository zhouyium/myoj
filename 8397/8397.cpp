#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=1e2+10;
LL a[N];
bool f[N];

void solve() {
	LL n=100;
	for (LL i=1;i<=n;i++) {
		a[i]=f[i]=0;
	}
	
	LL m,x,y;
	cin>>m>>x>>y;
	for (LL i=1;i<=m;i++) {
		cin>>a[i];
	}
	sort(a+1,a+m+1);
	
	//从1~m打标签
	for (LL i=1;i<=m;i++) {
		LL st=max(1ll,a[i]-x*y);
		LL ed=min(n,a[i]+x*y);
		for (LL j=st;j<=ed;j++) {
			f[j]=true;
		}
	}
	
	//统计结果
	LL res=0;
	for (LL i=1;i<=n;i++) {
		if (f[i]==false) {
			res++;
		}
	}
	cout<<res<<"\n";
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	freopen("04.in", "r", stdin);
	freopen("04.out", "w", stdout);

	int T=1;
	cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

