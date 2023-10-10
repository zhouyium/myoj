//4270产生随机数据 
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1e3+10;
LL a[MAXN][MAXN];
int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("00.in", "w", stdout);
	
	srand(time(0));
	
	LL n=38;
	cout<<n<<"\n";
	
	//随机一个数组
	LL maxx=1e2;
	LL minx=0;
	for (LL i=1; i<=n; i++) {
		for (LL j=1; j<=n; j++) {
			LL t=rand()%(maxx-minx+1)+minx;
			if (i==j) {
				t=0;
			}
			if (1==i && n==j) {
				t=0;
			}
			a[i][j]=t;
		}
	} 
	
	for (LL i=1; i<=n; i++) {
		for (LL j=1; j<=n; j++) {
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
	
	return 0;
}

