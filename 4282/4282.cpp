//http://47.110.135.197/problem.php?id=4282
//4282: §2 9 最长上升子序列
 
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN=1e3+10;
int a[MAXN];
int f[MAXN];//f[i]表示以数字a[i]结尾的最长上升子序列的最大长度
 
int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);
	int n;
	cin>>n;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
	}

	int maxx=0;
	for (int i=1; i<=n; i++) {
		f[i]=1;//以自己结束 
		for (int j=1; j<=i-1; j++) {
			if (a[i]>a[j]) {
				f[i]=max(f[i], f[j]+1);
			}
		}
		maxx=max(maxx, f[i]);
	}
	
	cout<<maxx<<"\n";
	
	return 0;
}

