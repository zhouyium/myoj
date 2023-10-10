//6635: 营养计划
//http://47.110.135.197/problem.php?id=6635 
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1E5+10;
LL a[N];
LL f[N];//f[i]表示前i个物品最大能提供的能量 
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
		cin>>a[i];
	}
	
	//任意连续三种方案中最多只选用了两种。
	f[1]=0;//不选第一个 
	f[2]=a[1];//选第一个 
	for (LL i=3; i<=n+1; i++) {
		f[i]=f[i-1];//第i个不选 
		f[i]=max(f[i], f[i-2]+a[i-1]);//选上一个 
		f[i]=max(f[i], f[i-3]+a[i-1]+a[i-2]);//选上两个 
	}
	cout<<f[n+1]<<"\n";

	return 0;
}

