//6485: °∏NOIP2012°πÕ¨”‡∑Ω≥Ã
//http://47.110.135.197/problem.php?id=6485
#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=1E6+10;

LL exgcd(LL a,LL b,LL &x,LL &y) {
	if (b==0) {
		x=1;y=0;
		return a;
	}
	LL gcd=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return gcd;
}

int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	
	//ax=1+by  ax%b=1%b
	LL a,b,x,y;
	cin>>a>>b;
	LL d=exgcd(a,b,x,y);
	b=b/d;
	x=(x%b+b)%b;
	cout<<x<<"\n";

	return 0;
}

