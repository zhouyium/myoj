//http://47.110.135.197/problem.php?id=5669
//5669: Segments with Small Set

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
int a[MAXN];
int cnt[MAXN];//统计数组 
int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	freopen("9.in", "r", stdin);
	freopen("9.out", "w", stdout);
	int n,K;
	cin>>n>>K;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
	}
	
	//[l, r]为最小满足题目要求的区间
	ll ans=0;
	ll sum=0;
	for (int l=1, r=1; r<=n; r++) {
		cnt[a[r]]++;
		if (1==cnt[a[r]]) {
			sum++;
		}
		//判断是否需要移动l
		while (sum>K) {
			cnt[a[l]]--;
			if (0==cnt[a[l]]) {
				sum--;
			}
			l++;
		} 
		ans+=(r-l+1);
	}
	cout<<ans<<"\n";
	return 0;
}

