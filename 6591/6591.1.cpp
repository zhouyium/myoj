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

LL mul(LL x,LL y,LL p) {
	//快速乘, (x*y)%p
	LL res=0;
	while (y) {
		if (y%2) {
			res=(res+x)%p;
		}
		x=(x+x)%p;
		y/=2;
	}
	return res%p;
}

LL excrt1(LL n) {
	LL m=a[1], ans=b[1];
	for (LL i=2; i<=n; i++) {
		//c就是前面bk-ans
		LL c=(b[i]-ans%a[i]+a[i])%a[i];
		LL x,y;
		LL d=exgcd(m, a[i], x, y);
		if ((b[i]-ans)%d) {
			return -1;//无解返回 -1
		}
		x=mul(x,c/d,a[i]/d);
		ans+=x*m;//更新ans
		m*=(a[i]/d);
		ans=(ans%m+m)%m;
	}
	return (ans%m+m)%m;
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
#if 0
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
	cout<<excrt1(n)<<"\n";
#endif	

	return 0;
}

