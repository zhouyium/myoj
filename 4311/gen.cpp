//4311产生随机数据 
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=2e2+10;
LL a[MAXN];
int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	freopen("06.in", "w", stdout);
	
	srand(time(0));
	
	LL n=100,m=100;
	cout<<n<<" "<<m<<"\n";
	
	//随机一个数组
	LL maxx=30;
	LL minx=10;
	LL x=1;
	for (LL i=1; i<=n; i++) {
		for (LL j=1; j<=n; j++) {
			cout<<x<<" ";
			LL t=rand()%(maxx-minx+1)+minx;
			x=x+t;
		}
		cout<<"\n";
	}
	
	return 0;
}

