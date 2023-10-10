//http://47.110.135.197/problem.php?id=5753

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
	freopen("08.in", "r", stdin);
	freopen("08.out", "w", stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1; i<=n; i++) {
		cin>>a[i];

		//维护单调性
		while (head<=tail&&a[que[tail]]<=a[i]) {
			tail--;
		}
		que[++tail]=i;
		//维护长度
		while (head<tail&&tail-head+1>m) {
			head++;
		}

		for (int j=head; j<=tail; j++) {
			cout<<a[que[j]]<<" ";
		}
		cout<<"\n";
	}

	return 0;
}

