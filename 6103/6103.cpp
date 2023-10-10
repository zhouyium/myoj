#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1E6+10;
char ans[MAXN];
int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	LL n;
	cin>>n;
	
	LL cnt=0;
	while (n) {
		if (n%2==1) {
			//ÆæÊý
			ans[++cnt]='A';
			n--;
		} else {
			ans[++cnt]='B';
			n/=2;
		}
	}
	
	for (LL i=cnt; i>=1; i--) {
		cout<<ans[i];
	}
	cout<<"\n";
	
	return 0;
}

