//6489: 表达整数的奇怪方式
//http://47.110.135.197/problem.php?id=6489
//ax =m%a
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=3E1;
LL a[N];//mo
LL b[N];

LL exgcd(LL a,LL b,LL &x,LL &y) {
	if (b==0) {
		x=1;y=0;
		return a;
	}
	LL d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}

//a1*x+b1=a2*x+b2
LL excrt(LL n) {
	LL a1=a[1], b1=b[1];
	LL x,y;
	for (LL i=2; i<=n; i++) {
		LL d=exgcd(a1, a[i], x, y);
		if ((b[i]-b1)%d) {
			return -1;
		}
		x*=(b[i]-b1)/d;
		LL t=abs(a[i]/d);
		x=(x%t+t)%t;
		b1=a1*x+b1;
		a1=abs(a1/d*a[i]);
	}
	return (b1%a1+a1)%a1;
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
	for (LL i=1; i<=n; i++) {
		cin>>a[i]>>b[i];
	}
	
	cout<<excrt(n)<<"\n";

	return 0;
}

