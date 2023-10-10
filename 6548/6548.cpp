//6548: 打印金字塔
//http://47.110.135.197/problem.php?id=6548
#include <bits/stdc++.h>
using namespace std;
using LL=long long;
int main() {
	freopen("07.out", "w", stdout);
	LL n;
	cin>>n;
	LL t=2*n-1;
	for (LL i=1; i<=n; i++) {
		//打前面空格
		for (LL j=1; j<=t; j++) {
			cout<<" ";
		}
		for (LL j=1; j<=i; j++) {
			cout<<"/\\  ";
		}
		cout<<"\n";
		for (LL j=1; j<=t-1; j++) {
			cout<<" ";
		}
		for (LL j=1; j<=i; j++) {
			cout<<"/__\\";
		}
		cout<<"\n";
		t=t-2;
	}
	return 0;
}
