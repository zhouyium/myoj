#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=2e3+10;
LL matches[N][N];

void solve() {
	LL n;
	cin>>n;
	// initialize a 2D array to store the number of each ordered pair that shows up
	for (LL i=1; i<=n; i++) {
		LL x,y;
		cin>>x>>y;
		matches[x][y]++;
	}
	
	// compute the maximum number of wins
	int maximumWins = matches[1][2] + matches[2][3] + matches[3][1];
	if(matches[1][3] + matches[3][2] + matches[2][1] > maximumWins) {
		maximumWins = matches[1][3] + matches[3][2] + matches[2][1]; 
	}
	cout<<maximumWins<<"\n";
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

