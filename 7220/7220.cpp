#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-7;

void solve(LL tc) {
	LL n,a,b;
	cin>>n>>a>>b;
	LL cnt1=0;//a的倍数
	LL cnt2=0;//b的倍数
	LL cnt3=0;//a和b的倍数 
	for (LL i=1; i<=n; i++) {
		LL x;
		cin>>x;
		if (x%a==0) {
			cnt1++;
		}
		if (x%b==0) {
			cnt2++;
		}
		if (x%a==0&&x%b==0) {
			cnt3++;
		}
	}
	
	if (cnt3) {
		cnt1++;
	}
	if (cnt1>cnt2) {
		cout<<"BOB\n";
	} else {
		cout<<"ALICE\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);

	int T;
	cin>>T;
	for (int i=1; i<=T; i++) {
	    solve(i);
	}
	return 0;
}

