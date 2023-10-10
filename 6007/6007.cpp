//6007: 【模板题】裴蜀定理
//http://47.110.135.197/problem.php?id=6007
#include <bits/stdc++.h>
using namespace std;
using LL=long long;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	//freopen("06.in", "r", stdin);
	//freopen("06.out", "w", stdout);
	
	LL n;
	cin>>n;
	LL gcd=0;
	for (LL i=1; i<=n; i++) {
		LL x;
		cin>>x;
		x=abs(x);
		gcd=__gcd(gcd, x);
	}
	cout<<gcd<<"\n";
	
    return 0;
}
