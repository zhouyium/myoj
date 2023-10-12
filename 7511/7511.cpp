//http://47.110.135.197/problem.php?id=7511
//7511: [CSES Problem Set] Stick Lengths

#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=2e5+10;
LL a[N];
LL n;

//>= min
LL cost(LL x) {
	//将所有木棒长度变为x的代价 
	LL sum=0;
	for (LL i=1; i<=n; i++) {
		sum+=abs(a[i]-x);
	}
	return sum;
}

bool check(LL m) {
	return cost(m)<cost(m+1);
}

LL bsearch(LL l, LL r) {
	while (l<r) {
		LL m=(l+r)/2;
		if (check(m)) {
			r = m;
		} else {
			l = m+1;
		}
	}
	return l;
}

void solve() {
	cin>>n;
	LL l=9e18;
	LL r=-9e18;
	for (LL i=1; i<=n; i++) {
		cin>>a[i];
		l = min(l, a[i]);
		r = max(r, a[i]);
	}
	
	//[l,r]中二分答案
	LL res = bsearch(l, r);
	cout<<cost(res)<<"\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

