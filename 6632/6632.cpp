//6632: 三进制加法
//http://47.110.135.197/problem.php?id=6632
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1E6+10;
int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);
	char a1,b1,c1,a2,b2,c2;
	cin>>a1>>b1>>c1>>a2>>b2>>c2;
	LL a=(a1-'0'+a2-'0')%3;
	LL b=(b1-'0'+b2-'0')%3;
	LL c=(c1-'0'+c2-'0')%3;
	cout<<a<<b<<c<<"\n";

	return 0;
}

