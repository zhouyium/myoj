//http://iai.sh.cn/problem/553
//Ô²»·Ñ¡Ö·

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 5e5+10;
LL n, a[N<<1], sumx[N<<1], sumy[N<<1];
LL ans = 4e18;

template<class T> inline void read(T &x){
	x = 0; T f = 1; char ch = getchar();
	while (!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
	while (isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	x *= f;
}

int main()
{
	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);
	
	read(n);
	for (int i=1; i <= n; i++){
		read(a[i]);
		a[i+n] = a[i];
	}
	for (int i= 1; i <= 2*n; i++){
		sumx[i] = sumx[i-1]+a[i];
		sumy[i] = sumy[i-1]+sumx[i];
	}
	for (int i=(n+1)/2; i<=(3*n-1)/2; i++){
		LL res = 2*sumy[i-1]-(sumy[i-(n-1)/2-1]+sumy[i+(n-1)/2-1])
				+ (n-1)/2*(sumx[i+(n-1)/2]-sumx[i-(n-1)/2-1]);
		if ((n&1)==0) res += n/2*a[i+n/2];
		ans = min(ans, res);
	}
	cout << ans;
	return 0;
}

