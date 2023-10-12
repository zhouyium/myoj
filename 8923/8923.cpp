#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;
const LL MO=1e9+7;

const int N=3e5+10;
LL a[N]; 

void solve() {
	LL n,m;
	cin>>n>>m;
	for(LL i=n;i>=0;i--){
		cin>>a[i];
	}
	
	LL res=0;
	LL coef=1;
	for(LL i=0;i<=n;i++){
		res=(res+(coef*a[i])%MO)%MO;
		coef=(coef*(m-i))%MO;
	}
	cout<<(res+MO)%MO<<"\n";
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	//freopen("12.in", "r", stdin);
	//freopen("12.out", "w", stdout);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

