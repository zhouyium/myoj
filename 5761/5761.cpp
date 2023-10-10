//http://47.110.135.197/problem.php?id=5761
//https://www.luogu.com.cn/problem/P1886
//https://www.acwing.com/problem/content/156/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=1e6+10;
int a[MAXN];
int que[MAXN];
int head=1;
int tail=0;

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int n,m;
	cin>>n>>m;
	//先找最小值 
	for (int i=1; i<=n; i++) {
		cin>>a[i];
		//保持单调性
		while (head<=tail && a[que[tail]]>=a[i]) {
			tail--;
		}
		que[++tail]=i;
		//保持大小
		while (head<=tail && i-m+1>que[head]) {
			head++;
		}
		//确保窗口大小为m 
		if (i>=m) {
			cout<<a[que[head]]<<" ";
		}
	}
	cout<<"\n";
	//最大值 
	head=1;
	tail=0;
	for (int i=1; i<=n; i++) {
		//保持单调性
		while (head<=tail && a[que[tail]]<=a[i]) {
			tail--;
		}
		que[++tail]=i;
		//保持大小
		while (head<=tail && i-m+1>que[head]) {
			head++;
		}
		//确保窗口大小为m 
		if (i>=m) {
			cout<<a[que[head]]<<" ";
		}
	}
	cout<<"\n";

	return 0;
}

