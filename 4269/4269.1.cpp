#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=2e2+10;
LL a[MAXN];
LL dp[MAXN];
LL pre[MAXN];//保存路径 
LL ans[MAXN];//路径答案 
int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	freopen("04.in", "r", stdin);
	freopen("04.out", "w", stdout);
	LL n;
	cin>>n;
	for (LL i=1; i<=n; i++) {
		cin>>a[i];
	}
	
	LL tot=1;
	LL max_pos=1;
	fill(pre, pre+n+1, -1);
	for (LL i=1; i<=n; i++) {
		dp[i]=1;
		for (LL j=1; j<i; j++) {
			if (a[i]>a[j] && dp[i]<dp[j]+1) {
				dp[i]=dp[j]+1;
				pre[i]=j;
				if (dp[i]>=tot) {
					tot=dp[i];
					max_pos=i;
				}
			}
		}
	}
	
	cout<<"max="<<tot<<"\n";
	LL cnt=0;
	while (max_pos!=-1) {
		ans[++cnt]=a[max_pos];
		max_pos=pre[max_pos];
	}
	for (LL i=cnt; i>=1; i--) {
		cout<<ans[i]<<" ";
	}
	cout<<"\n";

	return 0;
}

