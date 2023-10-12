//
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;
const LL MOD=32767;
const int MAXN=1e5+10;
LL n,q;
LL r[MAXN], c[MAXN];
LL xs,ys,xe,ye;
const int MAXM=2e3+10;
LL a[MAXM][MAXM];
LL b[MAXM][MAXM];

bool is_prime(LL x) {
	for (LL i=2; i*i<=x; i++) {
		for (LL j=2; j<=i; j++) {
			if (x%j==0) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);

	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);
	
	cin>>n>>q;
	for (LL i=1; i<=n;i++)  {
		cin>>r[i];
	}
	for (LL i=1; i<=n;i++)  {
		cin>>c[i];
	}
	for (LL i=1; i<=n; i++) {
		for (LL j=1; j<=n; j++) {
			a[i][j]=r[i]*c[j];
		}
	}
	
	while (q--) {
		cin>>xs>>ys>>xe>>ye;

		//递推一下 
		LL ans=0;
		b[xs][ys]=0; 
		for (LL i=xs; i<=xe; i++) {
			for (LL j=ys; j<=ye; j++) {
				if (i==xs&&j==ys) {
					b[xs][ys]=0;
				} else if (i==xs) {
					b[i][j]=__gcd(a[i][j], a[i][j-1]);
				} else if (j==ys) {
					b[i][j]=__gcd(a[i][j], a[i-1][j]);
				} else {
					b[i][j]=max(__gcd(a[i-1][j], a[i][j]), __gcd(a[i][j-1], a[i][j]));
				}
			}
		}
		
		//找答案
		if (1==b[xe][ye]) {
			cout<<"-1\n";
		} else {
			if (is_prime(b[xe][ye])) {
				cout<<ans<<"\n";
			} else {
				//不是素数
				for (LL i=2; i*i<=b[xe][ye]; i++) {
					if (is_prime(i) && b[xe][ye]%i==0) {
						cout<<b[xe][ye]/i<<"\n";
						break;
					}
				}
			}
		}
		//cout<<ans<<"\n";
	}
	
	return 0;
}

