//5950: 学习系列 —— 判断一个数字是否是斐波那契数列中的数字
//http://47.110.135.197/problem.php?id=5950
#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=1E6+10;
bool isPerfectSquare(LL x)
{
    LL s = sqrt(x);
    return (s*s == x);
}
bool isFibonacci(LL n)
{
    // n is Fibonacci if one of 5*n*n + 4 or 5*n*n - 4 or both
    // is a perfect square
    return (isPerfectSquare(5*n*n + 4)||isPerfectSquare(5*n*n - 4));
}

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
	cout<<n*n<<"\n";
	if (isFibonacci(n)) {
		cout<<"Yes\n";
	} else {
		cout<<"No\n";
	}
	return 0;
}

