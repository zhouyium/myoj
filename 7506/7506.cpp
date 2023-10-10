#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-7;

const int N=2e5+10;
struct NODE {
	LL h;
	bool f;
} a[N];
LL x;

//<= max
bool check(LL m) {
	if (a[m].f==false && a[m].h<=x) {
		return true;
	}
	return false;
}

LL bsearch(LL l, LL r) {
	while (l<r) {
		LL m=(l+r+1)/2;
		if (check(m)) {
			l = m;
		} else {
			r = m-1;
		}
	}
	return l;
}

bool mycmp(const NODE &x, const NODE &y) {
	return x.h<y.h;
}

void solve() {
	LL n,m;
	cin>>n>>m;
	for (LL i=1; i<=n; i++) {
		cin>>a[i].h;
		a[i].f = false;
	}
	sort(a+1, a+n+1, mycmp);
	
	for (LL i=1; i<=m; i++) {
		cin>>x;
		
		//¶þ·Ö
		LL res=bsearch(1, n);
		if (a[res].f==false) {
			a[res].f = true;
			cout<<a[res].h<<"\n";			
		} else {
			cout<<"-1\n";
		}
	}
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

