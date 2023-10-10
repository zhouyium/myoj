#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1E6+10;
LL fib[N];
int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	freopen("fib.out", "w", stdout);
	
	fib[1]=0;
	fib[2]=1;
	LL n=3;
	do {
		fib[n]=fib[n-1]+fib[n-2];
		n++;
	} while (fib[n-1]<=9e18 && fib[n-1]>=0);
	cout<<n-1<<"\n";
	for (LL i=1;i<n;i++) {
		cout<<fib[i]<<" ";
		if (i%10==0) {
			cout<<"\n";
		}
	}
	cout<<"\n";

	return 0;
}

