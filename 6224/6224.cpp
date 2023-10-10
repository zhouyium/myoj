//6224: Acowdemia I
//http://47.110.135.197/problem.php?id=6224
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1E5+10;
LL a[MAXN];
LL n,L;

LL calcIndex() {
	LL h=n;
	while (h>0 && a[h]<h) {
		h--;
	}
	return h;
}

bool mycmp(LL x, LL y) {
	return x>y;
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);

	cin>>n>>L;
	for (LL i=1; i<=n; i++) {
		cin>>a[i]; 
	}
	
	//计算当前的h-index 
	sort(a+1, a+n+1, mycmp);
	LL h=calcIndex();
	//cout<<h<<"\n";
	
	if (h!=n) {
		for (LL i=h+1; i>=1 && i>h-L+1; i--) {
			a[i]++;
		}
	}
	sort(a+1, a+n+1, mycmp);
	h=calcIndex();
	cout<<h<<"\n";	

	return 0;
}

