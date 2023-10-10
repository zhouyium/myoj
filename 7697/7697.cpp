#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=2e3+10;
char grid[N][N];

// define constants to indicate which squares are correct 
const char WRONG = '1';
const char RIGHT = '0';

void solve() {
	LL n;
	cin>>n;
	for (LL i=1; i<=n; i++) {
		for (LL j=1; j<=n; j++) {
			cin>>grid[i][j];
		}
	}
	
	int numTips = 0;
	// loop over the rectangles to consider from bottom to top, right to left
	for(int i=n; i>=1; i--) {
		for(int j=n; j>=1; j--) {
			if(grid[i][j] == WRONG) {
				// the rectangles with bottom-right corner at (i, j) needs to be toggled
				numTips++;
				for(int a=1; a<=i; a++) {
					for(int b=1; b<=j; b++) {
						// flip each entry in that rectangle
						if(grid[a][b] == WRONG) {
							grid[a][b] = RIGHT;
						}
						else {
							grid[a][b] = WRONG;
						}
					}
				}
			}
		}
	}	
	cout<<numTips<<"\n";
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

