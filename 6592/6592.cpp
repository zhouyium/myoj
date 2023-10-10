//6592: 【模板题】中国剩余定理 —— [TJOI2009] 猜数字
//http://47.110.135.197/problem.php?id=6592
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1E1+10;
LL a[N];//模
LL b[N];//余数

LL exgcd(LL a,LL b,LL &x,LL &y) {
	if (b==0) {
		x=1;y=0;
		return a;
	}
	LL d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}

//a1x+b1=a2x+b2 -> a1x-a2x=b2-b1
bool excrt(LL n, LL &ans) {
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
		b1=x*a1+b1;
		a1=abs(a1/d*a[i]);
	}
	ans=(b1%a1+a1)%a1;
	return true;
}


int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	LL n;
	cin>>n;
	for (LL i=1; i<=n; i++) {
		cin>>b[i];
	}
	for (LL i=1; i<=n; i++) {
		cin>>a[i];
	}
	LL ans;
	excrt(n, ans);
	cout<<ans<<"\n";

	return 0;
}

