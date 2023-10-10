//http://47.110.135.197/problem.php?id=6356
//6356: 愤怒的炸药

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5E4+10;
LL a[N];
LL n,K;

//最小的爆炸范围
bool check(LL mid) {
	//以mid为爆炸范围，需要几个炸弹
	LL tot=1;
	LL pos=1;
	LL ed=a[pos]+2*mid;
	
	while (ed<a[n]) {
		for (LL i=pos+1; i<=n; i++) {
			if (a[i]>ed) {
				pos=i;
				ed=a[pos]+2*mid;
				tot++;
				break;
			}
		}
	}
	
	return tot<=K;
}

LL bsearch(LL L, LL R) {
	LL mid;
	while (L<R) {
		mid=(L+R)/2;
		if (check(mid)) {
			R=mid;
		} else {
			L=mid+1;
		}
	}
	return L;
}

int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	cin>>n>>K;
	for (LL i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1, a+n+1);
	cout<<bsearch(1, a[n]-a[1])<<"\n";

	return 0;
}
