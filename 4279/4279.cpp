//4279: §2 9 【例9.8】合唱队形
///http://47.110.135.197/problem.php?id=4279 
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1E2+10;
LL a[N];
LL f[2][N];
int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("10.in", "r", stdin);
	//freopen("10.out", "w", stdout);
	LL n;
	cin>>n;
	for (LL i=1; i<=n; i++) {
		cin>>a[i];
	}
	//1到n求最长上升 
	for (LL i=1; i<=n; i++) {
		for (LL j=0; j<i; j++) {
			if (a[i]>a[j]) {
				f[0][i]=max(f[0][i], f[0][j]+1);
			}
		}
	}
	//从n到1求最长下降
	for (LL i=n; i>=1; i--)  {
		for (LL j=n+1; j>i; j--) {
			if (a[i]>a[j]) {
				f[1][i]=max(f[1][i], f[1][j]+1);
			}
		}
	}
	//枚举Ti，
	LL tot=0;
	for (LL i=1; i<=n; i++) {
		tot=max(f[0][i]+f[1][i]-1, tot);
	}
	cout<<n-tot<<"\n";

	return 0;
}

