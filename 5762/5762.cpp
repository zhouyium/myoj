//http://47.110.135.197/problem.php?id=5762
//5762: ·é»ðÌ¨

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
int a[MAXN];

int que[MAXN];
int head=1;
int tail=0;

int f[MAXN];

int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
	}
	
	for (int i=1; i<=n; i++) {
		while (head<=tail&&f[i-1]<f[que[tail]]) {
			tail--;
		}
		que[++tail]=i-1;
		while (head<=tail&&que[head]<i-m) {
			head++;
		}
		f[i]=f[que[head]]+a[i];//DP·½³Ì 
	}
	
	//
	int ans=INT_MAX;
	for (int i=n; i>n-m; i--) {
		ans=min(ans, f[i]);
	}
	cout<<ans<<"\n";

	return 0;
}

