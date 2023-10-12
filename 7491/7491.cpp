//http://47.110.135.197/problem.php?id=7491
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-7;

const int N=1e7+10;
string a[N];

void solve() {
	//freopen("04.in", "r", stdin);
	//freopen("04.out", "w", stdout);
	
	string s;
	while (getline(cin, s)) {
		stringstream ss(s);
		
		string x;
		LL cnt=0;
		while (ss>>x) {
			a[++cnt] = x;
		}
		
		cout<<cnt<<"\n";
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

