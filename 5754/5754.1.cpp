//http://47.110.135.197/problem.php?id=5754
//https://www.luogu.com.cn/problem/P1440
//求m区间内的最小值

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=2e6+10;
int a[MAXN];
int que[MAXN];
int tail=0;
int head=1;

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
	cout<<"0\n";
	for (int i=1; i<n; i++) {
		cin>>a[i];
		//保持单调性
		while (head<=tail&&a[que[tail]]>=a[i]) {
			tail--;
		}
		que[++tail]=i;
		//保持空间
		while (head<=tail&&que[head]<i-m+1) {
			head++;
		}
		cout<<a[que[head]]<<"\n";
	}

	return 0;
}

