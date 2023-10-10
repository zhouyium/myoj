#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=2e6+10;

void solve() {
	LL m,n,K;
	cin>>m>>n>>K;
	for (int i=1; i<=m; i++) {
		// get the next row to generate k copies of
		string currRow;
		cin>>currRow;
		
		// we will generate the same row K times
		for(int internalRow=1; internalRow<=K; internalRow++) {
			// loop over each character...
			for(int j=0; j<n; j++) {
				// and print it k times
				for(int a=1; a<=K; a++) {
					cout<<currRow[j];
				}
			}
			// we need to print a new line to indicate that we need to go to the next row
			cout<<"\n";
		}
	}
}

int main() {
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie (0);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

