//6511: 老周的礼物
//http://47.110.135.197/problem.php?id=6511
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1E6+10;
LL a[N];
LL n,m;

//以mid为界，看能否分为m个 
bool check(LL mid) {
	LL cnt=1;
	LL sum=a[1];
	for (LL i=2; i<=n; i++) {
		if (sum+a[i]<=mid) {
			sum+=a[i];
		} else {
			//新的一个包裹
			cnt++;
			sum=a[i];
		}
	}
	return cnt<=m;
}

//最大重量最小 min
LL bsearch(LL l, LL r) {
	LL mid;
	while (l<r) {
		mid=(l+r)/2;
		if (check(mid)) {
			r=mid; 
		} else {
			l=mid+1;
		}
	}
	return l;
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);
	cin>>n>>m;
	LL tot=0;
	for (LL i=1; i<=n; i++) {
		cin>>a[i];
		tot+=a[i];
	}
	
	cout<<bsearch(a[1], tot)<<"\n";

	return 0;
}

