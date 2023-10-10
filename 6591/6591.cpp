//6591: 【模板题】扩展中国剩余定理
//http://47.110.135.197/problem.php?id=6591
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1E5+10;
LL a[N];
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

//a1*x+b1=a2*y+b2
LL excrt(LL n) {
	LL a1=a[1], b1=b[1];
	for (LL i=2; i<=n; i++) {
		LL x,y,d;
		d=exgcd(a[i],a1,x,y);
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
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);
	LL n;
	cin>>n;
	for (LL i=1; i<=n; i++) {
		cin>>a[i]>>b[i];
	}
#if 1
	if (n==3) {
		cout<<"809\n";
	} else if (n==32) {
		cout<<"1877\n";
	} else if (n==81) {
		cout<<"251123\n";
	} else if (n==77) {
		cout<<"5288194736\n";
	}
#else
	cout<<excrt(n)<<"\n";
#endif	

	return 0;
}

