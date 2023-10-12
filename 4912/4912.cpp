#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=1e3+10;
string a[N];

bool check(LL x) {
	if (x%7==0) {
		return true;
	}
	//xÊÇ·ñº¬ÓÐ7
	LL t=x;
	while (t) {
		if (t%10==7) {
			return true;
		}
		t/=10;
	}
	
	return false;
}

void solve() {
	LL n,m,t;
	cin>>n>>m>>t;
	for (LL i=1; i<=n; i++) {
		cin>>a[i];
	}
	
	//Ä£Äâ
	queue<LL> b;
	for (LL i=m; i<=n; i++) {
		b.push(i);
	}
	for (LL i=1; i<m; i++) {
		b.push(i);
	}
	while (b.size()>1) {
		LL val=b.front();
		b.pop();
		if (false==check(t)) {
			b.push(val);
		}
		t++;
	}
	
	LL val=b.front();
	cout<<a[val]<<"\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);

	freopen("09.in", "r", stdin);
	freopen("09.out", "w", stdout);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

