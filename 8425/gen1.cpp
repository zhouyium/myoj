#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=2e6+10;

LL ran(LL l=1,LL r=1000) {
    if (l>r) {
        swap(l,r);
    }
    return rand()%(r-l+1)+l;
}

void solve() {
	LL n=1e6;
	cout<<n<<"\n";
	for (LL i=2;i<=n;i++) {
		LL type=ran(0,0);
		if (type==0) {
			cout<<i<<" 0\n";
		} else {
			cout<<"0 "<<i<<"\n";			
		}
	}
	cout<<"0 0\n";
}

int main() {
	srand(time(NULL));
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	//freopen("11.in", "r", stdin);
	freopen("10.in", "w", stdout);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

