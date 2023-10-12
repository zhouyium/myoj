#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;

const int N=2e6+10;

void solve() {
	LL n;
	while (cin>>n) {
		if (n==0) {
			break;
		}
		
		//分解因数法
		LL res=n;
		for (LL i=2;i*i<=n;i++) {
			if (n%i==0) {
				res=res/i*(i-1);
				//将i所有倍数删除
				while (n%i==0) {
					n/=i;
				}
			}
		}
		//是不是有大因数
		if (n>1) {
			res=res/n*(n-1);
		}
		cout<<res<<"\n";
	}
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	//freopen("marathon.in", "r", stdin);
	//freopen("marathon.out", "w", stdout);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

