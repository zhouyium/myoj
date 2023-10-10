#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=2e2+10;
const LL INF=0x3F3F3F3F;
LL a[MAXN];
LL dp[MAXN];
LL pre[MAXN];//记录位置 
LL ans[MAXN];//记录路径 

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	freopen("09.in", "r", stdin);
	freopen("09.1.out", "w", stdout);
	LL n;
	cin>>n;
	for (LL i=1; i<=n; i++) {
		cin>>a[i];
	}
	
	dp[1]=a[1];
	pre[1]=1;
	
	LL len=1;
	LL pos=1;
	for (LL i=2; i<=n; i++) {
		if (a[i]>dp[len]) {
			//说明这个数字可以加进来
			++len;
			dp[len]=a[i];
			++pos;
			pre[pos]=len;//记录从a[i]中1到n每个位置在dp的位置 
		} else  {
			int cnt=lower_bound(dp+1, dp+len+1, a[i]) - dp;
			dp[cnt] = a[i];
			pre[++pos] = cnt;
		} 
	}
	
	cout<<"max="<<len<<"\n";
	LL t=len;
	for (LL i=n; i>=1 && t>=1; i--) {
		if (pre[i]==t) {
			ans[t--]=a[i];
		}
	}
	for (LL i=1; i<=len; i++) {
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
	
	return 0;
}

